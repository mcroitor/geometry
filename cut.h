#ifndef MC_CUT_H
#define MC_CUT_H

#include "point.h"

namespace mc{
	/*
	* cuts
	*/
	template<size_type DIMENSION>
	struct cut{
		typedef point<DIMENSION> point_type;
		point_type a, b;

		cut(): a(point_type()), b(point_type()) {}
		cut(const point_type& p1, const point_type& p2): a(p1), b(p2) {}
		cut(const cut<DIMENSION>& p): a(p.a), b(p.b) {}
		cut operator = (const cut<DIMENSION>& p){
			a = p.a;
			b = p.b;
			return *this;
		}
	};

	template<size_type DIMENSION>
	bool operator == (const cut<DIMENSION>& a, const cut<DIMENSION>& b) {
		return (a.a == b.a) && (a.b == b.b);
	}

	template<size_type DIMENSION>
	std::ostream& operator << (std::ostream& os, const cut<DIMENSION>& p){
		os << "<" << p.a << ", " << p.b << ">";
		return os;
	}

	namespace g2d{
		typedef struct cut<2> cut2d;
	}
}
#endif