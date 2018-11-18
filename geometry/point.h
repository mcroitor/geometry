#ifndef MC_POINT_H
#define MC_POINT_H
#include <algorithm>
#include <string>
#include <sstream>
#include <initializer_list>
#include "utilities.h"

namespace mc {
    namespace geometry {

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

            double& operator[](const size_t& index) {
                return coords[index];
            }

            const double& operator[](const size_t& index) const {
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
            size_t i;
            for (i = 0; i != DIMENSION; ++i) {
                if (mc::dbl_compare(p1[i], p2[i]) == false)
                    return false;
            }
            return true;
        }

        template<size_t DIMENSION>
        std::ostream& operator<<(std::ostream& out, const point<DIMENSION>& p) {
            out << p.to_string();
            return out;
        }
    }
}

#endif /* POINT_H */

