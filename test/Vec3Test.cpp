//
// Created by matt on 22/11/18.
//

#include "catch.hpp"
#include "Vec3.h"

TEST_CASE("Vec3 Addition", "[Vec3]") {
    SECTION("Default vectors") {
        REQUIRE(Vec3() + Vec3() == Vec3());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Vec3(1, 2, 3) + Vec3() == Vec3(1, 2, 3));
        REQUIRE(Vec3() + Vec3(1, 2, 3) == Vec3(1, 2, 3));
        REQUIRE(Vec3(0, 0, 0) + Vec3(0, 0, 0) == Vec3());
    }
    SECTION("Normal operation") {
        REQUIRE(Vec3(1, 1, 1) + Vec3(1, 1, 1) == Vec3(2, 2, 2));
    }
}

TEST_CASE("Vec3 Subtraction", "[Vec3]") {
    SECTION("Default vectors") {
        REQUIRE(Vec3() - Vec3() == Vec3());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Vec3(1, 2, 3) - Vec3() == Vec3(1, 2, 3));
        REQUIRE(Vec3() - Vec3(1, 2, 3) == Vec3(-1, -2, -3));
        REQUIRE(Vec3(0, 0, 0) - Vec3(0, 0, 0) == Vec3());
    }
    SECTION("Normal operation") {
        REQUIRE(Vec3(1, 1, 1) - Vec3(1, 1, 1) == Vec3(0, 0, 0));
    }
}