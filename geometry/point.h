#ifndef MC_POINT_H
#define MC_POINT_H
#include <algorithm>
#include <string>
#include <array>
#include <sstream>
#include <initializer_list>

namespace mc {
    namespace geometry {
        template<size_t _DIMENSION>
        using array = std::array<double, _DIMENSION>;

        template<size_t _DIMENSION>
        class point {
            array<_DIMENSION> coords;

            void nill() {
                std::fill(coords.begin(), coords.end(), 0);
            }
        public:
            typedef mc::geometry::point<_DIMENSION> POINT_TYPE;

            enum {
                DIMENSION = _DIMENSION
            };

            point() {
                nill();
            }

            point(const std::initializer_list<double>& a) {
                std::copy(a.begin(), a.end(), coords.begin());
            }

            point(const array<_DIMENSION>& a) {
                std::copy(a.begin(), a.end(), coords.begin());
            }

            point(const POINT_TYPE& p) {
                std::copy(p.coords.begin(), p.coords.end(), coords.begin());
            }

            double& x(const size_t& index) {
                return coords[index];
            }

            POINT_TYPE operator=(const POINT_TYPE& p) {
                std::copy(p.coords, p.coords + _DIMENSION, coords);
                return *this;
            }

            std::string to_string() const {
                std::ostringstream strout;
                strout << "(";
                typename array<_DIMENSION>::const_iterator i = coords.begin();
                while (i != coords.end()) {
                    strout << (*i);
                    ++i;
                    if (i != coords.end()) strout << ", ";
                }
                strout << ")";
                return strout.str();
            }
        };

        template<size_t DIMENSION>
        bool operator==(const point<DIMENSION>& p1, const point<DIMENSION>& p2) {
            // TODO#: move to utilities
            const double EPS = 0.000001;
            auto abs = [] (double p) {
                return (p > 0) ? p : -p;
            };
            auto dbl_compare = [&abs, &EPS] (double x, double y) {
                return abs(x - y) < EPS;
            };
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

#endif /* POINT_H */

