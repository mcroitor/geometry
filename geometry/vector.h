#ifndef MC_VECTOR_H
#define MC_VECTOR_H

#include <algorithm>
#include <array>

#include "point.h"


namespace mc {
    namespace geometry {
        template<size_t _DIMENSION>
        using array = std::array<double, _DIMENSION>;
        
        typedef double distance_type;

        template<size_t _DIMENSION>
        class vector {
            array<_DIMENSION> x;

            void nill() {
                std::fill(x.begin(), x.end(), 0.);
            }
        public:
            typedef mc::geometry::vector<_DIMENSION> VECTOR_TYPE;

            enum {
                DIMENSION = _DIMENSION
            };

            vector() {
                nill();
            }

            vector(const point<_DIMENSION>& start, const point<_DIMENSION>& end) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] = end.x(i) - start.x(i);
                }
            }

            vector(const array<_DIMENSION>& a) {
                std::copy(a.begin(), a.end(), x.begin());
            }

            vector(const std::initializer_list<double>& a) {
                std::copy(a.begin(), a.end(), x.begin());
            }

            vector(const vector<_DIMENSION>& p) {
                std::copy(p.x.begin(), p.x.end(), x.begin());
            }

            vector<_DIMENSION>& operator=(const vector<_DIMENSION>& p) {
                std::copy(p.x.begin(), p.x.end(), x.begin());
                return *this;
            }

            double& operator[](const size_t& index) {
                return x[index];
            }

            void operator+=(const vector<_DIMENSION>& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] += p.x[i];
                }
            }

            void operator-=(const vector<_DIMENSION>& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] -= p.x[i];
                }
            }

            void operator*=(const double& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] *= p;
                }
            }

            void operator/=(const double& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    x[i] /= p;
                }
            }

            vector<_DIMENSION> operator-() const {
                vector<_DIMENSION> tmp;
                tmp -= *this;
                return tmp;
            }

            distance_type module() const {
                size_t i = 0;
                distance_type result = 0;
                for (; i != _DIMENSION; ++i) {
                    result += x[i] * x[i];
                }
                return std::sqrt(result);
            }

            std::string to_string() const {
                std::ostringstream strout;
                strout << "[";
                typename array<_DIMENSION>::const_iterator i = x.begin();
                while (i != x.end()) {
                    strout << (*i);
                    ++i;
                    if (i != x.end()) strout << ", ";
                }
                strout << "]";
                return strout.str();
            }

            bool equal(const vector<_DIMENSION>& p) const {
                return std::equal(x.begin(), x.end(), p.x.begin());
            }
        };

        template<size_t DIMENSION>
        bool operator==(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            return p1.equal(p2);
        }

        template<size_t DIMENSION>
        bool operator||(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            vector<DIMENSION> tmp1 = normalize(p1);
            vector<DIMENSION> tmp2 = normalize(p2);
            return tmp1.equal(tmp2) || tmp1.equal(-tmp2);
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator+(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            vector<DIMENSION> tmp(p1);
            tmp += p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator-(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            vector<DIMENSION> tmp(p1);
            tmp -= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator*(const vector<DIMENSION>& p1, const double& p2) {
            vector<DIMENSION> tmp(p1);
            tmp *= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator*(const double& p2, const vector<DIMENSION>& p1) {
            vector<DIMENSION> tmp(p1);
            tmp *= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator/(const vector<DIMENSION>& p1, const double& p2) {
            vector<DIMENSION> tmp(p1);
            tmp /= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        std::ostream& operator<<(std::ostream& out, const vector<DIMENSION>& p) {
            out << p.to_string();
            return out;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> normalize(const vector<DIMENSION>& p) {
            vector<DIMENSION> tmp(p);
            tmp /= p.module();
            return tmp;
        }

        template<size_t DIMENSION>
        distance_type operator*(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            distance_type result = 0.0;
            size_t i;
            for (i = 0; i != DIMENSION; ++i) {
                result += p1[i] * p2[i];
            }
            return result;
        }
    }
}
#endif /* VECTOR_H */

