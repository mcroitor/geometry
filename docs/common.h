/* 
 * File:   common.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 16 ianuarie 2019, 15:37
 */

#ifndef COMMON_H
#define COMMON_H

#include <array>


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
                using element_type = element<TYPE, SIZE>;
                
                element(std::initializer_list<element_type>& _scalars): std::copy(_scalars.begin(), _scalars.end(), scalars.begin()){
                    
                }

                virtual element_type operator=(const element_type& param) {
                    std::copy(param.scalars, param.scalars + SIZE, scalars);
                    return *this;
                }

                virtual bool operator==(const element_type& param) const {
                    return std::equal(param.scalars, param.scalars + SIZE, scalars);
                }
                
                size_t dimension() const {
                    return SIZE;
                }
                TYPE scalar(size_t index) const{
                    return scalars[index];
                }
                TYPE operator [] (size_t index) const {
                    return scalar(index);
                }

                virtual element_type operator+=(const element_type&) = 0;
                virtual element_type operator*=(const TYPE&) = 0;
                virtual element_type operator-(int) const = 0;
                
            protected:
                std::array<TYPE, SIZE> scalars;
            };

            template<typename TYPE, size_t SIZE>
            element<TYPE, SIZE> operator+(const element<TYPE, SIZE>& left, const element<TYPE, SIZE>& right) {
                element<TYPE, SIZE> tmp = left;
                left += right;
                return left;
            }

            template<typename TYPE, size_t SIZE>
            element<TYPE, SIZE> operator*(const element<TYPE, SIZE>& left, TYPE right) {
                element<TYPE, SIZE> tmp = left;
                left *= right;
                return left;
            }

            template<typename TYPE, size_t SIZE>
            element<TYPE, SIZE> operator*(TYPE left, const element<TYPE, SIZE>& right) {
                element<TYPE, SIZE> tmp = right;
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
            
            template<typename TYPE, size_t SIZE>
            std::array<element<TYPE, SIZE>, SIZE> basis();
            
            template<size_t SIZE>
            std::array<element<int, SIZE>, SIZE> basis<int, SIZE>(){
                std::array<element<int, SIZE>, SIZE> _basis;
// TODO #: implement this!
                return _basis;
            }
            
            template<size_t SIZE>
            std::array<element<double, SIZE>, SIZE> basis<double, SIZE>(){
                std::array<element<double, SIZE>, SIZE> _basis;
// TODO #: implement this!
                return _basis;
            }
        }
    }
}

#endif /* COMMON_H */

