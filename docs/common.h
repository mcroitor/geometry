/* 
 * File:   common.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 16 ianuarie 2019, 15:37
 */

#ifndef COMMON_H
#define COMMON_H

namespace mc {
    namespace space {
        namespace abstract {

            struct element {
                virtual element operator=(const element&) = 0;
                virtual bool operator==(const element&) const = 0;
            };
        }
        namespace linear {
            template<typename TYPE, size_t SIZE>
            struct element : public abstract::element {
                typedef TYPE scalar_type;

                virtual element<TYPE, SIZE> operator=(const element<TYPE, SIZE>& param) {
                    std::copy(param.scalars, param.scalars + SIZE, scalars);
                    return *this;
                }

                virtual bool operator==(const element<TYPE, SIZE>& param) const {
                    return std::equal(param.scalars, param.scalars + SIZE, scalars);
                }
                
                size_t dimension() const {
                    return SIZE;
                }

                virtual element<TYPE, SIZE> operator+=(const element<TYPE, SIZE>&) = 0;
                virtual element<TYPE, SIZE> operator*=(const TYPE&) = 0;
                virtual element<TYPE, SIZE> operator-(int) const = 0;
            protected:
                TYPE scalars[SIZE];
            };

            template<typename TYPE>
            element<TYPE> operator+(const element<TYPE>& left, const element<TYPE>& right) {
                element<TYPE> tmp = left;
                left += right;
                return left;
            }

            template<typename TYPE>
            element<TYPE> operator*(const element<TYPE>& left, TYPE right) {
                element<TYPE> tmp = left;
                left *= right;
                return left;
            }

            template<typename TYPE>
            element<TYPE> operator*(TYPE left, const element<TYPE>& right) {
                element<TYPE> tmp = right;
                right *= left;
                return right;
            }
            /**
             * common test of operations need:
             * 1) A + B = B + A
             * 2) A + (B + C) = (A + B) + C
             * 3) A + -A = 0
             * 3.1) exists 0
             * 4) a * (b * A) = (a * b) * A
             * 5) 1 * A = A
             * 6) a * (A + B) = a * A + a * B
             * 7) (a + b) * A = a * A + b * A
             */
        }
    }
}

#endif /* COMMON_H */

