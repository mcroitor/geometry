#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "point.h"
#include "vector.h"

TEST_CASE("points can be created", "[point]") {
    mc::geometry::point<6> point;
    REQUIRE(point.DIMENSION == 6);
    for (size_t index = 0; index != point.DIMENSION; ++index) {
        REQUIRE(point.x(index) == 0);
    }
}

TEST_CASE("points can be initialized", "[point]") {
    mc::geometry::point<5> point = {1, 2, 3, 4, 5};
    REQUIRE(point.DIMENSION == 5);
    for (size_t index = 0; index != point.DIMENSION; ++index) {
        REQUIRE(point.x(index) == index + 1);
    }
}

TEST_CASE("vectors as geometric objects", "[vector]") {
    mc::geometry::point<5> point1 = {1, 2, 3, 4, 5};
    mc::geometry::point<5> point2 = {5, 4, 3, 2, 1};
    mc::geometry::vector<5> vector1(point1, point2);
    mc::geometry::vector<5> _vector = {4, 2, 0, -2, -4};
    mc::geometry::vector<5> vector2 = {2, 1, 0, -1, -2};
    REQUIRE(vector1.DIMENSION == 5);

    REQUIRE(vector1[0] == 4);
    REQUIRE(vector1[1] == 2);
    REQUIRE(vector1[2] == 0);
    REQUIRE(vector1[3] == -2);
    REQUIRE(vector1[4] == -4);

    SECTION("compare vectors") {
        REQUIRE(vector1 == _vector);
        REQUIRE(vector1 != vector2);

        SECTION("collinear vectors") {
            REQUIRE((vector1 || vector2));
        }
    }
}