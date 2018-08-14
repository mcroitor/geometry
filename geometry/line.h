#ifndef MC_LINE_H
#define MC_LINE_H

#include "point.h"
#include "vector.h"
#include "cut.h"

namespace mc {
    namespace geometry {
        enum POS_TYPE { MATCH, PARALLEL, INTERSECT};

        /*
         * lines
         */

        template<size_t DIMENSION>
        struct line {
            point<DIMENSION> p;
            vector<DIMENSION> a;

            line(const point<DIMENSION>& p1, const point<DIMENSION>& p2) : p(p1), a(normalize(vector<DIMENSION>(p1, p2))) {
            }

            line(const cut<DIMENSION>& c) : p(c.a), a(normalize(vector<DIMENSION>(c.a, c.b))) {
            }

            line(const line<DIMENSION>& l) : p(l.p), a(l.a) {
            }

            ~line() {
            }

            line<DIMENSION> operator=(const line<DIMENSION>& l) {
                p = l.p;
                a = l.a;

                return *this;
            }
            
            // #TODO: add to_string
        };

        template<size_t DIMENSION>
        POS_TYPE operator==(const line<DIMENSION>& l1, const line<DIMENSION>& l2) {
            if (!(l1.a == l2.a) && !(l1.a == -l2.a)) {
                return INTERSECT;
            }
            return MATCH;
        }
    }
}
#endif