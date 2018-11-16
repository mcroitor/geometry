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
            point<_DIMENSION> p;
            vector<_DIMENSION> a;
        public:
            typedef mc::geometry::point<_DIMENSION> POINT_TYPE;

            enum {
                DIMENSION = _DIMENSION
            };

            line(const point<_DIMENSION>& p1, const point<_DIMENSION>& p2) : p(p1), a(normalize(vector<_DIMENSION>(p1, p2))) {
            }

            line(const cut<_DIMENSION>& c) : p(c.a), a(normalize(vector<_DIMENSION>(c.a, c.b))) {
            }

            line(const line<_DIMENSION>& l) : p(l.p), a(l.a) {
            }

            ~line() {
            }

            line<_DIMENSION> operator=(const line<_DIMENSION>& l) {
                p = l.p;
                a = l.a;

                return *this;
            }

            // #TODO: add to_string
        };

        template<size_t _DIMENSION>
        POS_TYPE operator==(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2) {
            if (!(l1.a == l2.a) && !(l1.a == -l2.a)) {
                return INTERSECT;
            }
            return MATCH;
        }
    }
}
#endif