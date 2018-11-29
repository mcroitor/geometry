#ifndef MC_LINE_H
#define MC_LINE_H

#include "point.h"
#include "vector.h"
#include "cut.h"

namespace mc {
    namespace geometry {

        enum POS_TYPE {
            MATCH, PARALLEL, INTERSECT
        };

        /*
         * lines
         */

        template<size_t _DIMENSION>
        class line {
            point<_DIMENSION> point_;
            vector<_DIMENSION> vector_;
        public:
            typedef mc::geometry::point<_DIMENSION> point_type;
            typedef mc::geometry::line<_DIMENSION> line_type;
            typedef mc::geometry::vector<_DIMENSION> vector_type;

            enum {
                DIMENSION = _DIMENSION
            };

            line(const point_type& p1, const point_type& p2) : point_(p1), vector_(normalize(vector_type(p1, p2))) {
            }

            line(const point_type& p, const vector_type& v) : point_(p), vector_(normalize(v)) {
            }

            line(const cut<_DIMENSION>& c) : point_(c.a), vector_(normalize(vector_type(c.a, c.b))) {
            }

            line(const line_type& l) : point_(l.point_), vector_(l.vector_) {
            }

            ~line() {
            }

            line<_DIMENSION> operator=(const line_type& l) {
                point_ = l.point_;
                vector_ = l.vector_;

                return *this;
            }

            const vector_type& direction_vector() const {
                return vector_;
            }

            const point_type& point() const {
                return point_;
            }

            const vector_type position_vector() const {
                return vector_type(point_, point_type());
            }

            bool contains(const point_type& p) const {
                if (p == point_) {
                    return true;
                }
                vector_type v(point_, p);
                return v || vector_;
            }

            /**
             * line representation. vector parametric form:
             *  <r> = <position_vector> + t * <direction_vector>
             * @return 
             */
            std::string to_string() const {
                std::ostringstream strout;
                strout << "<r> = " << this->position_vector() << " + t * " << this->direction_vector();
                return strout.str();
            }

            const bool match(const line_type& l) const {
                return (direction_vector() || l.direction_vector()) &&
                        (contains(l.point()));
            }

            const bool parallel(const line_type& l) const {
                return direction_vector() || l.direction_vector() &&
                        !(contains(l.point()));
            }

            const bool intersect(const line_type& l) const {
                return !(direction_vector() || l.direction_vector());
            }
        };

        /**
         * check if lines are parallel, intersect or match
         * @param l1
         * @param l2
         * @return 
         */
        template<size_t _DIMENSION>
        POS_TYPE operator==(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2) {
            if (l1.intersect(l2) == true) {
                return INTERSECT;
            }
            if (l1.match(l2) == true) {
                return MATCH;
            }
            return PARALLEL;
        }

        template<size_t _DIMENSION>
        point<_DIMENSION> intersection(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2) {
            if (l1.intersect(l2) == false) {
                throw std::domain_error("lines does not intersects!");
            }
            // 1)   P[1] = L1.P[1] + t1 * L1.V[1], P[1] = L2.P[1] + t2 * L2.V[1]
            //      P[N] = L1.P[N] + t1 * L1.V[N], P[N] = L2.P[N] + t2 * L2.V[N]
            // 2)   t1 * L1.V[1] - t2 * L2.V[1] = L2.P[1] - L1.P[1]
            //      t1 * L1.V[N] - t2 * L2.V[N] = L2.P[N] - L1.P[N]
            // 3)   t1 * L1.V[1] * L2.V[N] - t2 * L2.V[1] * L2.V[N] = (L2.P[1] - L1.P[1]) * L2.V[N]
            //      t1 * L1.V[N] * L2.V[1] - t2 * L2.V[N] * L2.V[1] = (L2.P[N] - L1.P[N]) * L2.V[1]
            // 4)   t1 * L1.V[1] * L2.V[N] - t1 * L1.V[N] * L2.V[1] = (L2.P[1] - L1.P[1]) * L2.V[N] 
            //                                                      - (L2.P[N] - L1.P[N]) * L2.V[1]
            //      U = L1.V[1] * L2.V[N] - L1.V[N] * L2.V[1]
            //      W = (L2.P[1] - L1.P[1]) * L2.V[N] - (L2.P[N] - L1.P[N]) * L2.V[1]
            //      t1 = W / U
            const vector<_DIMENSION>& v1 = l1.direction_vector();
            const vector<_DIMENSION>& v2 = l2.direction_vector();

            const point<_DIMENSION>& p1 = l1.point();
            const point<_DIMENSION>& p2 = l2.point();
            mc::distance_type U = v1[0] * v2[_DIMENSION - 1] - v1[_DIMENSION - 1] * v2[0];
            if (mc::dbl_compare(0, U) == true) {
                throw std::logic_error("division by 0");
            }
            mc::distance_type W = (p2[0] - p1[0]) * v2[_DIMENSION - 1] -
                    (p2[_DIMENSION - 1] - p1[_DIMENSION - 1]) * v2[0];
            vector<_DIMENSION> v = v1 * W / U + l1.position_vector();
            return move(point<_DIMENSION>(), v);
        }
    }
}
#endif