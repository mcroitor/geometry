#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "point.h"

TEST_CASE( "points can be created", "[point]" ) {
    mc::geometry::point<6> point;
    REQUIRE( point.DIMENSION == 6 );
    for(size_t index = 0; index != point.DIMENSION; ++index){
        REQUIRE( point.x(index) == 0 );
    }
}