/* 
 * File:   utilities.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 18 November 2018, 09:46
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <array>
#include <utility>
#include <cmath>

using namespace std::rel_ops;

namespace mc {
    namespace geometry {
        using namespace std::rel_ops;
    }
    const double EPS = 0.000001;

    template<size_t _DIMENSION>
    using array = std::array<double, _DIMENSION>;

    typedef double distance_type;

    double abs(double p) {
        return (p > 0) ? p : -p;
    };

    bool dbl_compare(double x, double y) {
        return abs(x - y) < EPS;
    };
}

#endif /* UTILITIES_H */

