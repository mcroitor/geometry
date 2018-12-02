# Line
Line is a common primitive for each space. Is defined by point and direction vector.

## Example of use

## Point definition
```C++
enum POS_TYPE {
    MATCH, PARALLEL, INTERSECT
};

template<size_t _DIMENSION>
class line {
    point<_DIMENSION> point_;
    vector<_DIMENSION> vector_;
public:
    typedef mc::geometry::point<_DIMENSION> point_type;
    typedef mc::geometry::line<_DIMENSION> line_type;
    typedef mc::geometry::vector<_DIMENSION> vector_type;

    enum { DIMENSION = _DIMENSION };

    line(const point_type& p1, const point_type& p2);
    line(const point_type& p, const vector_type& v);
    line(const cut<_DIMENSION>& c);
    line(const line_type& l);
   ~line();

    line<_DIMENSION> operator=(const line_type& l);
    const vector_type& direction_vector() const;
    const point_type& point() const;
    const vector_type position_vector() const;
    bool contains(const point_type& p) const;
    std::string to_string() const;
    const bool match(const line_type& l) const;
    const bool parallel(const line_type& l) const;
    const bool intersect(const line_type& l) const;
};

template<size_t _DIMENSION>
POS_TYPE operator==(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2);

template<size_t _DIMENSION>
point<_DIMENSION> intersection(const line<_DIMENSION>& l1, const line<_DIMENSION>& l2);
```
