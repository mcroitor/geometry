```C++
template < size_t _DIMENSION >
class point {
	array < double, _DIMENSION > coords;

	void nill();
public:
	typedef mc::geometry::point < _DIMENSION > POINT_TYPE;
	enum {	DIMENSION = _DIMENSION	};

	point() ;
	point(const array < double, _DIMENSION > & a) ;
	point(const POINT_TYPE & p) ;
	double & x(const size_t & index);
	POINT_TYPE operator = (const POINT_TYPE & p) ;
	std::string to_string() const;
};

template < class DIMENSION >
bool operator == (const point < DIMENSION > & p1, const point < DIMENSION > & p2) ;
```