/* 
 * File:   vector_test.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 18 November 2018, 10:43
 */

#include <stdlib.h>
#include <iostream>
#include "vector.h"

/*
 * Simple C++ Test Suite
 */

void testVector() {
    mc::geometry::vector<6> _vector = {1, 2, 3, 4, 5, 6};
    for (size_t i = 0; i != _vector.DIMENSION; ++i) {
        if (_vector[i] != i + 1) {
            std::cout << "%TEST_FAILED% time=0 testname=testVector (vector_test) message=error message sample" << std::endl;
        }
    }
}

void testModule() {
    mc::geometry::vector<4> _vector = {1, 1, 1, 1};
    mc::distance_type result = _vector.module();
    if (result != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testModule (vector_test) message=error message sample" << std::endl;
    }
}

void testTo_string() {
    mc::geometry::vector<4> _vector = {1, 0, -1, 1};
    std::string result = _vector.to_string();
    if (result != "[1, 0, -1, 1]") {
        std::cout << "%TEST_FAILED% time=0 testname=testTo_string (vector_test) message=error message sample" << std::endl;
        std::cout << "vector = " << result << std::endl;
    }
}

void testEqual() {
    mc::geometry::vector<4> _vector = {2, 1, 0, -1};
    if (_vector.equal({2, 1, 0, -1}) != true) {
        std::cout << "%TEST_FAILED% time=0 testname=testEqual (vector_test) message=error message sample" << std::endl;
    }
    if (_vector.equal({1, 1, 0, -1}) == true) {
        std::cout << "%TEST_FAILED% time=0 testname=testEqual (vector_test) message=error message sample" << std::endl;
    }
}

void testNormalize() {
    // using namespace mc::geometry;
    using vector = mc::geometry::vector<4>;
    const vector p = {1, 1, 1, 1};
    vector result = normalize(p);
    if (result != vector({0.5, 0.5, 0.5, 0.5})) {
        std::cout << "%TEST_FAILED% time=0 testname=testNormalize (vector_test) message=error message sample" << std::endl;
        std::cout << "vector = " << result << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% vector_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testVector (vector_test)" << std::endl;
    testVector();
    std::cout << "%TEST_FINISHED% time=0 testVector (vector_test)" << std::endl;

    std::cout << "%TEST_STARTED% testModule (vector_test)" << std::endl;
    testModule();
    std::cout << "%TEST_FINISHED% time=0 testModule (vector_test)" << std::endl;

    std::cout << "%TEST_STARTED% testTo_string (vector_test)" << std::endl;
    testTo_string();
    std::cout << "%TEST_FINISHED% time=0 testTo_string (vector_test)" << std::endl;

    std::cout << "%TEST_STARTED% testEqual (vector_test)" << std::endl;
    testEqual();
    std::cout << "%TEST_FINISHED% time=0 testEqual (vector_test)" << std::endl;

    std::cout << "%TEST_STARTED% testNormalize (vector_test)" << std::endl;
    testNormalize();
    std::cout << "%TEST_FINISHED% time=0 testNormalize (vector_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

