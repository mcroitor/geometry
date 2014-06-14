#ifndef MC_POINT_H
#define	MC_POINT_H
#include "../array.h"
#include <algorithm>
namespace mc {
    namespace geometry {

        template<size_t DIMMENTION>
        class point {
            mc::array<double, DIMMENTION> coords;
        public:
            typedef mc::geometry::point<DIMMENTION> POINT_TYPE;

            point() {
            }

            double& x(const size_t& index) {
                return coords[index];
            }

            POINT_TYPE operator =(const POINT_TYPE& p) {
                std::copy(p.coords, p.coords + DIMMENTION, coords);
                return *this;
            }
        };

        template<class DIMMENTION>
        bool operator ==(const point<DIMMENTION>& p1, const point<DIMMENTION>& p2) {
            size_t i;
            for (i = 0; i != DIMMENTION; ++i) {
                if (mc::dbl_compare(p1.x(i), p2.x(i)) == false)
                    return false;
            }
            return true;
        }
    }
}

#endif	/* POINT_H */

