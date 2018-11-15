#ifndef MC_CUT_H
#define MC_CUT_H

#include "point.h"

namespace mc {
    namespace geometry {

        /*
         * cuts
         */
        template<size_t DIMENSION>
        struct cut {
            typedef point<DIMENSION> point_type;
            point_type a, b;

            cut() : a(point_type()), b(point_type()) {
            }

            cut(const point_type& p1, const point_type& p2) : a(p1), b(p2) {
            }

            cut(const cut<DIMENSION>& p) : a(p.a), b(p.b) {
            }

            cut operator=(const cut<DIMENSION>& p) {
                a = p.a;
                b = p.b;
                return *this;
            }
            
            // #TODO: add to_string
        };

        template<size_t DIMENSION>
        bool operator==(const cut<DIMENSION>& a, const cut<DIMENSION>& b) {
            return (a.a == b.a) && (a.b == b.b);
        }

        template<size_t DIMENSION>
        std::ostream& operator<<(std::ostream& os, const cut<DIMENSION>& p) {
            os << "<" << p.a << ", " << p.b << ">";
            return os;
        }

        namespace g2d {
            typedef struct cut<2> cut2d;
        }
    }
}
#endif