#ifndef MC_CUT_H
#define MC_CUT_H

#include "point.h"
#include "vector.h"

namespace mc {
    namespace geometry {

        /*
         * cuts
         */
        template<size_t _DIMENSION>
        class cut {
            point<_DIMENSION> _a, _b;
        public:

            enum {
                DIMENSION = _DIMENSION
            };
            typedef point<_DIMENSION> point_type;
            typedef cut<_DIMENSION> cut_type;

            cut() : _a(point_type()), _b(point_type()) {
            }

            cut(const point_type& p1, const point_type& p2) : _a(p1), _b(p2) {
            }

            cut(const cut_type& p) : _a(p.a()), _b(p.b()) {
            }

            cut operator=(const cut_type& p) {
                _a = p.a();
                _b = p.b();
                return *this;
            }

            point_type a() const {
                return _a;
            }

            point_type b() const {
                return _b;
            }

            std::string to_string() const {
                std::ostringstream strout;
                strout << "<" << this->a() << ", " << this->b() << ">";
                return strout.str();
            }
            
            bool contains(const point_type& p) const{
                cut_type ap(this->a(), p), bp(this->b(), p);
                return dbl_compare(ap.length() + bp.length(),this->length());
            }
            distance_type length() const{
                return vector<DIMENSION>(this->a(), this->b()).module();
            }
        };

        template<size_t _DIMENSION>
        bool operator==(const cut<_DIMENSION>& a, const cut<_DIMENSION>& b) {
            return (a.a() == b.a()) && (a.b() == b.b());
        }

        template<size_t _DIMENSION>
        std::ostream& operator<<(std::ostream& os, const cut<_DIMENSION>& p) {
            os << p.to_string();
            return os;
        }

    }
}
#endif