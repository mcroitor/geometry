#ifndef MC_POINT_H
#define	MC_POINT_H
#include <algorithm>
#include <string>
#include <array>
namespace mc {
    namespace geometry {
        using array = std::array;
        template<size_t _DIMENSION>
        class point {
            array<double, _DIMENSION> coords;

            void nill() {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] = 0;
                }
            }
        public:
            typedef mc::geometry::point<_DIMENSION> POINT_TYPE;
            enum {DIMENSION = _DIMENSION};

            point() {
                nill();
            }

            point(const array<double, _DIMENSION>& a) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i)
                    x[i] = a[i];
            }

            point(const POINT_TYPE& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i)
                    x[i] = p.x[i];
            }

            double& x(const size_t& index) {
                return coords[index];
            }

            POINT_TYPE operator =(const POINT_TYPE& p) {
                std::copy(p.coords, p.coords + _DIMENSION, coords);
                return *this;
            }

            std::string to_string() const {
                std::ostringstream strout;
                strout << "(";
                typename array<double, _DIMENSION>::const_iterator i = coords.begin();
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
            // TODO#: move to utilities
            const double EPS = 0.000001;
            auto abs = [] (double p) {return (p > 0) ? p : -p; };
            auto dbl_compare = [] (double x, double y) { return abs(x - y) < EPS;};
            // end #TODO
            size_t i;
            for (i = 0; i != DIMENSION; ++i) {
                if (dbl_compare(p1.x(i), p2.x(i)) == false)
                    return false;
            }
            return true;
        }
    }
}

#endif	/* POINT_H */

