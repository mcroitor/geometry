/* 
 * File:   point_test.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 14 august 2018, 16:03
 */

#include <stdlib.h>
#include <iostream>
#include "point.h"

/*
 * Simple C++ Test Suite
 */

void testPoint() {
    mc::geometry::point<3> _point;
    if (_point.DIMENSION != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testPoint (point_test) message=error message sample" << std::endl;
    }
}

void testPoint2() {
    const std::array<double, 7> a = {1., 2, 3, 4, 5, 6, 7.0};
    mc::geometry::point<7> _point(a);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPoint2 (point_test) message=error message sample" << std::endl;
    }
}

void testPoint3() {
    using point = mc::geometry::point<4>;
    const point p = {4, 3, 2, 1};
    point _point(p);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPoint3 (point_test) message=error message sample" << std::endl;
    }
}

void testX() {
    using point = mc::geometry::point<4>;
    const size_t& index = 2;
    point _point;
    double& result = _point.x(index);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testX (point_test) message=error message sample" << std::endl;
    }
}

void testToString() {
    using point = mc::geometry::point<4>;
    point _point;
    std::string result = _point.to_string();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (point_test) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% point_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testPoint (point_test)" << std::endl;
    testPoint();
    std::cout << "%TEST_FINISHED% time=0 testPoint (point_test)" << std::endl;

    std::cout << "%TEST_STARTED% testPoint2 (point_test)" << std::endl;
    testPoint2();
    std::cout << "%TEST_FINISHED% time=0 testPoint2 (point_test)" << std::endl;

    std::cout << "%TEST_STARTED% testPoint3 (point_test)" << std::endl;
    testPoint3();
    std::cout << "%TEST_FINISHED% time=0 testPoint3 (point_test)" << std::endl;

    std::cout << "%TEST_STARTED% testX (point_test)" << std::endl;
    testX();
    std::cout << "%TEST_FINISHED% time=0 testX (point_test)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (point_test)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (point_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

