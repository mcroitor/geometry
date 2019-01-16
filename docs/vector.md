# Vector
Vector primitive. On each N-dimensional space vector is represented by N double numbers. 
Library propose next functionality: 
 * create vector, 
 * copy existent vector, 
 * get i-coordinate of vector, 
 * compare vector with another or check collinearity
 * some simple arithmetic operations (+, -, * with double, / to double) and 
 * generate string representation (for printing, by example).
## Example of use

## Point definition
```C++
typedef double distance_type;

template<size_t _DIMENSION>
class vector {
    array<_DIMENSION> coords;

    void nill();
public:
    typedef mc::geometry::vector<_DIMENSION> vector_type;
    typedef mc::geometry::point<_DIMENSION> point_type;

    enum { DIMENSION = _DIMENSION };

    vector();

    vector(const point<_DIMENSION>& start, const point<_DIMENSION>& end);
    vector(const array<_DIMENSION>& a);
    vector(const std::initializer_list<double>& a);
    vector(const vector<_DIMENSION>& p);

    vector<_DIMENSION>& operator=(const vector<_DIMENSION>& p);
    double& operator[](const size_t& index);
    const double& operator[](const size_t& index) const;

    void operator+=(const vector<_DIMENSION>& p);
    void operator-=(const vector<_DIMENSION>& p);

    void operator*=(const double& p);
    void operator/=(const double& p);

    vector<_DIMENSION> operator-() const;
    distance_type module() const;
    std::string to_string() const;
    bool equal(const vector<_DIMENSION>& p) const;
};

template<size_t DIMENSION>
bool operator==(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2);
template<size_t DIMENSION>
bool operator||(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2);
template<size_t DIMENSION>
vector<DIMENSION> operator+(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2);
template<size_t DIMENSION>
vector<DIMENSION> operator-(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2);
template<size_t DIMENSION>
vector<DIMENSION> operator*(const vector<DIMENSION>& p1, const double& p2);
template<size_t DIMENSION>
vector<DIMENSION> operator*(const double& p2, const vector<DIMENSION>& p1);
template<size_t DIMENSION>
vector<DIMENSION> operator/(const vector<DIMENSION>& p1, const double& p2);

template<size_t DIMENSION>
std::ostream& operator<<(std::ostream& out, const vector<DIMENSION>& p);

template<size_t DIMENSION>
vector<DIMENSION> normalize(const vector<DIMENSION>& p);

template<size_t DIMENSION>
distance_type operator*(const vector<DIMENSION>& p1, const vector<DIMENSION>& p2);
template<size_t DIMENSION>
point<DIMENSION> move(const point<DIMENSION>& p, const vector<DIMENSION>& v);
```

