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
            point<_DIMENSION> _p;
            vector<_DIMENSION> _a;
        public:
            typedef mc::geometry::point<_DIMENSION> point_type;
            typedef mc::geometry::line<_DIMENSION> line_type;
            typedef mc::geometry::vector<_DIMENSION> vector_type;

            enum {
                DIMENSION = _DIMENSION
            };

            line(const point_type& p1, const point_type& p2) : _p(p1), _a(normalize(vector_type(p1, p2))) {
            }

            line(const cut<_DIMENSION>& c) : _p(c.a), _a(normalize(vector_type(c.a, c.b))) {
            }

            line(const line_type& l) : _p(l._p), _a(l._a) {
            }

            ~line() {
            }

            line<_DIMENSION> operator=(const line_type& l) {
                _p = l._p;
                _a = l._a;

                return *this;
            }

            const vector_type& a() const {
                return _a;
            }

            const point_type& p() const {
                return _p;
            }

            bool contains(const point_type& p) const {
                vector_type v(_p, p);
                return v || _a;
            }
            // #TODO: add to_string
        };

        template<size_t _DIMENSION>
        POS_TYPE operator==(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2) {
            if (!(l1.a() || l2.a())) {
                return INTERSECT;
            }
            if ((l1.a() || l2.a()) && l1.contains(l2.p())) {
                return MATCH;
            }
            return PARALLEL;
        }
    }
}
#endif