#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "point.h"
#include "vector.h"
#include "line.h"

TEST_CASE("points can be created", "[point]") {
    mc::geometry::point<6> point;
    REQUIRE(point.DIMENSION == 6);
    for (size_t index = 0; index != point.DIMENSION; ++index) {
        REQUIRE(point[index] == 0);
    }
}

TEST_CASE("points can be initialized", "[point]") {
    mc::geometry::point<5> point = {1, 2, 3, 4, 5};
    REQUIRE(point.DIMENSION == 5);
    for (size_t index = 0; index != point.DIMENSION; ++index) {
        REQUIRE(point[index] == index + 1);
    }
}

TEST_CASE("vectors as geometric objects", "[vector]") {
    using namespace mc::geometry;
    point<5> point1 = {1, 2, 3, 4, 5};
    point<5> point2 = {5, 4, 3, 2, 1};
    vector<5> vector1(point1, point2);
    vector<5> _vector = {4, 2, 0, -2, -4};
    vector<5> vector2 = {2, 1, 0, -1, -2};
    vector<5> vector3 = {2, 1, 0, -1, -1};

    SECTION("check space dimension") {
        REQUIRE(vector1.DIMENSION == 5);
    }

    SECTION("check vector initialization") {
        REQUIRE(vector1[0] == 4);
        REQUIRE(vector1[1] == 2);
        REQUIRE(vector1[2] == 0);
        REQUIRE(vector1[3] == -2);
        REQUIRE(vector1[4] == -4);
    }

    SECTION("compare vectors") {
        REQUIRE(vector1 == _vector);
        REQUIRE(vector3 != _vector);
        // TODO# : interesting property of require
        REQUIRE((vector1 != vector2));

        SECTION("collinear vectors") {
            REQUIRE((vector1 || vector2) == true);
            REQUIRE((vector1 || vector3) == false);
        }
    }
}

TEST_CASE("lines can be created", "[line]") {
    const size_t SIZE = 3;
    using point = mc::geometry::point<SIZE>;
    using vector = mc::geometry::vector<SIZE>;
    using line = mc::geometry::line<SIZE>;

    SECTION("check space dimension") {
        REQUIRE(point::DIMENSION == SIZE);
        REQUIRE(vector::DIMENSION == SIZE);
        REQUIRE(line::DIMENSION == SIZE);
    }

    point A({1, 0, 0});
    point A_chord({2, 0, 0});
    point B({0, 0, 1});

    SECTION("check points initialization") {
        REQUIRE(A[0] == 1);
        REQUIRE(A[1] == 0);
        REQUIRE(A[2] == 0);
        REQUIRE(B[0] == 0);
        REQUIRE(B[1] == 0);
        REQUIRE(B[2] == 1);
    }
    vector AB(A, B);

    SECTION("check vector initialization") {
        REQUIRE(AB[0] == -1);
        REQUIRE(AB[1] == 0);
        REQUIRE(AB[2] == 1);
    }

    line A_B_0(A, B);
    line A_B_1(A, AB);
    line A_B_2(A_chord, AB);

    SECTION("check line initialization") {
        REQUIRE(A_B_0.point() == A);
        REQUIRE(A_B_0.direction_vector() == mc::geometry::normalize(AB));
    }

    SECTION("check if line contains point") {
        std::cout << "line0 = " << A_B_0.to_string() << ", point_line_1 = " << A_B_1.point() << std::endl;
        std::cout << "line0 = " << A_B_0.to_string() << ", point_line_2 = " << A_B_2.point() << std::endl;
        REQUIRE(A_B_0.contains(A_B_1.point()) == true);
        REQUIRE(A_B_0.contains(A_B_2.point()) == false);
    }
    
    SECTION("check if line contains point") {
        vector v0 = A_B_0.direction_vector();
        vector v1 = A_B_1.direction_vector();
        vector v2 = A_B_2.direction_vector();
        std::cout << "vector_line_0 = " << v0.to_string() << std::endl;
        std::cout << "vector_line_1 = " << v1.to_string() << std::endl;
        std::cout << "vector_line_2 = " << v2.to_string() << std::endl;
        REQUIRE((v0 || v1) == true);
        REQUIRE((v0 || v2) == true);
    }    

    SECTION("check line positioning") {
        std::cout << "line0 = " << A_B_0.to_string() << std::endl;
        std::cout << "line1 = " << A_B_1.to_string() << std::endl;
        std::cout << "line2 = " << A_B_2.to_string() << std::endl;
        REQUIRE((A_B_0 == A_B_1) == mc::geometry::MATCH);
        REQUIRE((A_B_0 == A_B_2) == mc::geometry::PARALLEL);
    }

    SECTION("line to_string") {
        REQUIRE(A_B_0.to_string() == "<r> = <-1, 0, 0> + t * <-0.707107, 0, 0.707107>");
    }
}

TEST_CASE("intersection of lines", "[line]") {
    const size_t SIZE = 2;
    using point = mc::geometry::point<SIZE>;
    using vector = mc::geometry::vector<SIZE>;
    using line = mc::geometry::line<SIZE>;
    
    point O = {0, 0};
    point A = {1, 1};
    point B = {2, 0};
    
    line OA = {O, A};
    line AB = {A, B};
    
    point TestPoint = mc::geometry::intersection(OA, AB);
    REQUIRE(TestPoint == A);
}