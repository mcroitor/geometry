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
        };

        /**
         * check if lines are parallel, intersect or match
         * @param l1
         * @param l2
         * @return 
         */
        template<size_t _DIMENSION>
        POS_TYPE operator==(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2) {
            if (!(l1.direction_vector() || l2.direction_vector())) {
                return INTERSECT;
            }
            if ((l1.direction_vector() || l2.direction_vector()) && l1.contains(l2.point())) {
                return MATCH;
            }
            return PARALLEL;
        }
    }
}
#endif