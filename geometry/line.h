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
            typedef mc::geometry::point<_DIMENSION> POINT_TYPE;

            enum {
                DIMENSION = _DIMENSION
            };

            line(const point<_DIMENSION>& p1, const point<_DIMENSION>& p2) : _p(p1), _a(normalize(vector<_DIMENSION>(p1, p2))) {
            }

            line(const cut<_DIMENSION>& c) : _p(c.a), _a(normalize(vector<_DIMENSION>(c.a, c.b))) {
            }

            line(const line<_DIMENSION>& l) : _p(l._p), _a(l._a) {
            }

            ~line() {
            }

            line<_DIMENSION> operator=(const line<_DIMENSION>& l) {
                _p = l._p;
                _a = l._a;

                return *this;
            }

            const vector<_DIMENSION>& a() const {
                return _a;
            }

            const point<_DIMENSION>& p() const {
                return _p;
            }

            bool contains(const point<_DIMENSION>& p) const {
                vector<_DIMENSION> v(_p, p);
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
                return PARALLEL;
            }
            return MATCH;
        }
    }
}
#endif