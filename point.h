#ifndef MC_POINT_H
#define	MC_POINT_H
#include "../array.h"
#include <algorithm>
#include <string>
namespace mc {
    namespace geometry {

        template<size_t DIMENSION>
        class point {
            mc::array<double, DIMENSION> coords;

            void nill() {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] = 0;
                }
            }
        public:
            typedef mc::geometry::point<DIMENSION> POINT_TYPE;

            point() {
                nill();
            }

            point(const array<double, DIMENSION>& a) {
                size_t i = 0;
                for (; i != DIMENSION; ++i)
                    x[i] = a[i];
            }

            point(const POINT_TYPE& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i)
                    x[i] = p.x[i];
            }

            double& x(const size_t& index) {
                return coords[index];
            }

            POINT_TYPE operator =(const POINT_TYPE& p) {
                std::copy(p.coords, p.coords + DIMENSION, coords);
                return *this;
            }

            std::string toString() const {
                std::ostringstream strout;
                strout << "(";
                typename array<double, DIMENSION>::const_iterator i = coords.begin();
                while (i != coords.end()) {
                    strout << (*i);
                    ++i;
                    if (i != coords.end()) strout << ", ";
                }
                strout << ")";
                return strout.str();
            }
        };

        template<class DIMENSION>
        bool operator ==(const point<DIMENSION>& p1, const point<DIMENSION>& p2) {
            size_t i;
            for (i = 0; i != DIMENSION; ++i) {
                if (mc::dbl_compare(p1.x(i), p2.x(i)) == false)
                    return false;
            }
            return true;
        }
    }
}

#endif	/* POINT_H */

