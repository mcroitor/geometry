# Point
Point is a very first primitive for each space. On each N-dimensional space point 
is represented by N double numbers. Library propose next functionality: 
 * create point, 
 * copy existent point, 
 * get i-coordinate of point, 
 * compare point with another and 
 * generate string representation (for printing, by example).
## Example of use

## Point definition
```C++
template < size_t _DIMENSION >
class point {
	array < double, _DIMENSION > coords;

	void nill();
public:
	typedef mc::geometry::point < _DIMENSION > POINT_TYPE;
	enum {	DIMENSION = _DIMENSION	};

	point() ;
        point(const std::initializer_list<double>& a);
	point(const array < double, _DIMENSION > & a) ;
	point(const POINT_TYPE & p) ;
	double& operator[](const size_t& index);
	const double& operator[](const size_t& index) const;
	POINT_TYPE operator = (const POINT_TYPE & p) ;
        bool equals(const point_type& p) constș
	std::string to_string() const;
};

template < size_t DIMENSION >
bool operator == (const point < DIMENSION > & p1, const point < DIMENSION > & p2) ;
template<size_t DIMENSION>
std::ostream& operator<<(std::ostream& out, const point<DIMENSION>& p);
```
