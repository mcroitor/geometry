#ifndef MC_CUT_H
#define MC_CUT_H

#include "point.h"

namespace mc {
    namespace geometry {

        /*
         * cuts
         */
        template<size_t _DIMENSION>
        struct cut {

            enum {
                DIMENSION = _DIMENSION
            };
            typedef point<_DIMENSION> point_type;
            point_type a, b;

            cut() : a(point_type()), b(point_type()) {
            }

            cut(const point_type& p1, const point_type& p2) : a(p1), b(p2) {
            }

            cut(const cut<_DIMENSION>& p) : a(p.a), b(p.b) {
            }

            cut operator=(const cut<_DIMENSION>& p) {
                a = p.a;
                b = p.b;
                return *this;
            }

            // #TODO: add to_string
        };

        template<size_t _DIMENSION>
        bool operator==(const cut<_DIMENSION>& a, const cut<_DIMENSION>& b) {
            return (a.a == b.a) && (a.b == b.b);
        }

        template<size_t _DIMENSION>
        std::ostream& operator<<(std::ostream& os, const cut<_DIMENSION>& p) {
            os << "<" << p.a << ", " << p.b << ">";
            return os;
        }

        namespace g2d {
            typedef struct cut<2> cut2d;
        }
    }
}
#endif