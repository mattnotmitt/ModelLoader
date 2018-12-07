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

TEST_CASE("Vec3 multiplication", "[Vec3]") {
    SECTION("Default vectors") {
        REQUIRE(Vec3() * Vec3() == Vec3());
        REQUIRE(Vec3().dot(Vec3())== 0 );
        REQUIRE(Vec3() * 0 == Vec3());
    }
    SECTION("Default vectors X instantiated vectors") {
        REQUIRE(Vec3(1, 2, 3) * Vec3() == Vec3(0, 0, 0));
        REQUIRE(Vec3() * Vec3(1, 2, 3) == Vec3(0, 0, 0));
        REQUIRE(Vec3(0, 0, 0) * Vec3(0, 0, 0) == Vec3());
        REQUIRE(Vec3(1, 2, 3) * 2 == Vec3(2, 4, 6));
    }
    SECTION("Default vectors . instantiated vectors") {
        REQUIRE(Vec3(1, 2, 3).dot(Vec3()) == 0);
        REQUIRE(Vec3().dot(Vec3(1, 2, 3)) == 0);
        REQUIRE(Vec3(0, 0, 0).dot(Vec3(0, 0, 0)) == 0);
    }
    SECTION("Normal operation") {
        REQUIRE(Vec3(1, 1, 1) * Vec3(2, 2, 2) == Vec3(0, 0, 0));
        REQUIRE(Vec3(1,1,1).dot(Vec3(2,2,2))== 6);
    }
}