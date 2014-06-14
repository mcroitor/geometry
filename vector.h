#ifndef MC_VECTOR_H
#define	MC_VECTOR_H

namespace mc {
    namespace geometry {
        typedef double distance_type;

        template<size_t DIMENSION>
        struct vector {
            array<double, DIMENSION> x;

            void nill() {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] = 0;
                }
            }

            vector() {
                nill();
            }

            vector(const point<DIMENSION>& start, const point<DIMENSION>& end) {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] = end[i] - start[i];
                }
            }

            vector(const array<double, DIMENSION>& a) {
                size_t i = 0;
                for (; i != DIMENSION; ++i)
                    x[i] = a[i];
            }

            vector(const vector<DIMENSION>& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i)
                    x[i] = p.x[i];
            }

            vector<DIMENSION>& operator =(const vector<DIMENSION>& p) {
                std::copy(p.x.begin(), p.x.end(), x.begin());
                return *this;
            }

            double& operator [](const size_t& index) {
                return x[index];
            }

            void operator +=(const vector<DIMENSION>& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] += p.x[i];
                }
            }

            void operator -=(const vector<DIMENSION>& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] -= p.x[i];
                }
            }

            void operator *=(const double& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] *= p;
                }
            }

            void operator /=(const double& p) {
                size_t i = 0;
                for (; i != DIMENSION; ++i) {
                    x[i] /= p;
                }
            }

            vector<DIMENSION> operator -() const {
                vector<DIMENSION> tmp;
                tmp -= *this;
                return tmp;
            }

            distance_type length() const {
                size_t i = 0;
                distance_type result = 0;
                for (; i != DIMENSION; ++i) {
                    result += x[i] * x[i];
                }
                return mc::sqrt(result);
            }

            std::string toString() const {
                std::ostringstream strout;
                strout << "[";
                typename array<double, DIMENSION>::const_iterator i = x.begin();
                while (i != x.end()) {
                    strout << (*i);
                    ++i;
                    if (i != x.end()) strout << ", ";
                }
                strout << "]";
                return strout.str();
            }
        };

        template<size_t DIMENSION>
        bool operator ==(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            return p1.x == p2.x;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator +(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            vector<DIMENSION> tmp(p1);
            tmp += p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator -(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2) {
            vector<DIMENSION> tmp(p1);
            tmp -= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator *(const vector<DIMENSION>& p1, const double& p2) {
            vector<DIMENSION> tmp(p1);
            tmp *= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator *(const double& p2, const vector<DIMENSION>& p1) {
            vector<DIMENSION> tmp(p1);
            tmp *= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> operator /(const vector<DIMENSION>& p1, const double& p2) {
            vector<DIMENSION> tmp(p1);
            tmp /= p2;
            return tmp;
        }

        template<size_t DIMENSION>
        std::ostream& operator <<(std::ostream& out, const vector<DIMENSION>& p) {
            out << p.toString();
            return out;
        }

        template<size_t DIMENSION>
        vector<DIMENSION> normalize(const vector<DIMENSION>& p) {
            vector<DIMENSION> tmp(p);
            tmp /= p.length();
            return tmp;
        }
    }
}
#endif	/* VECTOR_H */

