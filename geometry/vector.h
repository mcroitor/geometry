#ifndef MC_VECTOR_H
#define MC_VECTOR_H


#include <utility>
#include <algorithm>

#include "utilities.h"
#include "point.h"

namespace mc {
    namespace geometry {

        template<size_t _DIMENSION>
        class vector {
            array<_DIMENSION> coords;

            void nill() {
                std::fill(coords.begin(), coords.end(), 0.);
            }
        public:
            typedef mc::geometry::vector<_DIMENSION> vector_type;
            typedef mc::geometry::point<_DIMENSION> point_type;

            enum {
                DIMENSION = _DIMENSION
            };

            vector() {
                nill();
            }

            vector(const point_type& start, const point_type& end) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    coords[i] = end[i] - start[i];
                }
            }

            vector(const array<_DIMENSION>& a) {
                std::copy(a.begin(), a.end(), coords.begin());
            }

            vector(const std::initializer_list<double>& a) {
                std::copy(a.begin(), a.end(), coords.begin());
            }

            vector(const vector_type& p) {
                std::copy(p.coords.begin(), p.coords.end(), coords.begin());
            }

            vector_type& operator=(const vector_type& p) {
                std::copy(p.coords.begin(), p.coords.end(), coords.begin());
                return *this;
            }

            double& operator[](const size_t& index) {
                return coords[index];
            }
            
            const double& operator[](const size_t& index) const {
                return coords[index];
            }

            void operator+=(const vector_type& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    coords[i] += p.coords[i];
                }
            }

            void operator-=(const vector_type& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    coords[i] -= p.coords[i];
                }
            }

            void operator*=(const double& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    coords[i] *= p;
                }
            }

            void operator/=(const double& p) {
                size_t i = 0;
                for (; i != _DIMENSION; ++i) {
                    coords[i] /= p;
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
                    result += coords[i] * coords[i];
                }
                return std::sqrt(result);
            }

            std::string to_string() const {
                std::ostringstream strout;
                strout << "<";
                typename array<_DIMENSION>::const_iterator i = coords.begin();
                while (i != coords.end()) {
                    strout << (*i);
                    ++i;
                    if (i != coords.end()) strout << ", ";
                }
                strout << ">";
                return strout.str();
            }

            bool equal(const vector_type& p) const {
                return std::equal(coords.begin(), coords.end(), p.coords.begin(), dbl_compare);
            }
        };

        template<size_t DIMENSION>
        bool operator==(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            return p1.equal(p2);
        }

        /**
         * check if vectors are collinear.
         * @param p1
         * @param p2
         * @return 
         */
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

        /**
         * normalize vector. normalized vector has length 1.
         * @param p
         * @return 
         */
        template<size_t DIMENSION>
        vector<DIMENSION> normalize(const vector<DIMENSION>& p) {
            vector<DIMENSION> tmp(p);
            tmp /= p.module();
            return tmp;
        }

        /**
         * scalar product of 2 vectors
         * @param p1
         * @param p2
         * @return 
         */
        template<size_t DIMENSION>
        distance_type operator*(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            distance_type result = 0.0;
            size_t i;
            for (i = 0; i != DIMENSION; ++i) {
                result += p1[i] * p2[i];
            }
            return result;
        }
        
        /**
         * Move a point on direction specified by vector
         * @param p
         * @param v
         * @return new point
         */
        template<size_t DIMENSION>
        point<DIMENSION> move(const point<DIMENSION>& p, const vector<DIMENSION>& v){
            point<DIMENSION> tmp = p;
            size_t index;
            for(index = 0; index != DIMENSION; ++index){
                tmp[index] += v[index];
            }
            return tmp;
        }
    }
}
#endif /* VECTOR_H */

