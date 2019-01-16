# Cut
Cut is a primitive, is defined as a set o points between 2 points.

## Example of use

## Point definition
```C++
template<size_t _DIMENSION>
class cut {
    point<_DIMENSION> point_a, point_b;
public:

    enum {
        DIMENSION = _DIMENSION
    };
    typedef point<_DIMENSION> point_type;
    typedef cut<_DIMENSION> cut_type;

    cut();
    cut(const point_type& p1, const point_type& p2);
    cut(const cut_type& p);

    cut operator=(const cut_type& p);
    point_type a() const;
    point_type b() const;

    std::string to_string() const;    
    bool contains(const point_type& p) const;
    distance_type length() const;
};

template<size_t _DIMENSION>
bool operator==(const cut<_DIMENSION>& a, const cut<_DIMENSION>& b);

template<size_t _DIMENSION>
std::ostream& operator<<(std::ostream& os, const cut<_DIMENSION>& p);
```
