/* 
 * File:   cut_test.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 14 august 2018, 16:02
 */

#include <stdlib.h>
#include <iostream>
#include "cut.h"

/*
 * Simple C++ Test Suite
 */

void testCut() {
    mc::geometry::cut<2> _cut;
    if (_cut.DIMENSION != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testCut (cut_test) message=error message sample" << std::endl;
    }
}

void testCut2() {
    using namespace mc::geometry;
    using point = point<4>;
    using cut = cut<point::DIMENSION>;
    const point p1;
    const point p2 = {1, 2, 1, 0};
    cut _cut(p1, p2);
    if (_cut.a() != point() && _cut.b() != point()) {
        std::cout << "%TEST_FAILED% time=0 testname=testCut2 (cut_test) message=error message sample" << std::endl;
    }
}

void testCut3() {
    using namespace mc::geometry;
    using point = point<4>;
    using cut = cut<point::DIMENSION>;
    const cut p = {{0, 1, 2, 3}, {4, 3, 2, 1}};
    cut _cut(p);
    if (_cut.a() != point({0, 1, 2, 3})) {
        std::cout << "%TEST_FAILED% time=0 testname=testCut3 (cut_test) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% cut_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCut (cut_test)" << std::endl;
    testCut();
    std::cout << "%TEST_FINISHED% time=0 testCut (cut_test)" << std::endl;

    std::cout << "%TEST_STARTED% testCut2 (cut_test)" << std::endl;
    testCut2();
    std::cout << "%TEST_FINISHED% time=0 testCut2 (cut_test)" << std::endl;

    std::cout << "%TEST_STARTED% testCut3 (cut_test)" << std::endl;
    testCut3();
    std::cout << "%TEST_FINISHED% time=0 testCut3 (cut_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

