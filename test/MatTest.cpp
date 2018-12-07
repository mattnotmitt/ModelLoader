//
// Created by eeysrdo on 06/12/2018.
//

#include "catch.hpp"
#include "Matrix.h"

TEST_CASE("Mat Addition", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() + Mat() == Mat());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)) + Mat()
        == Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)));
        REQUIRE(Mat() + Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0))
        == Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)));
        REQUIRE(Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) +
        Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) == Mat());
    }
    SECTION("Normal operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) +
        Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0))
        == Mat(Vec3(2.0, 2.0, 2.0),Vec3(2.0, 2.0, 2.0),Vec3(2.0, 2.0, 2.0)));
    }
}


TEST_CASE("Mat Subtraction", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() - Mat() == Mat());
    }
    SECTION("Default vectors - instantiated vectors") {
        REQUIRE(Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)) - Mat()
        == Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)));
        REQUIRE(Mat() - Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0))
        == Mat(Vec3(-1.0, -2.0, -3.0), Vec3(-1.0, -2.0, -3.0), Vec3(-1.0, -2.0, -3.0)));
        REQUIRE(Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) -
        Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) == Mat());
    }
    SECTION("Normal operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) -
        Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0))
        == Mat());
    }
}


TEST_CASE("Mat Multiplication", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() * Mat() == Mat());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)) * Mat()
        == Mat());
        REQUIRE(Mat() * Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0))
        == Mat());
        REQUIRE(Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) *
        Mat(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0)) == Mat());
    }
    SECTION("Normal 2 Matrices operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) *
        Mat(Vec3(1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0), Vec3(0.0, 0.0, 1.0))
        == Mat(Vec3(1.0, 1.0, 1.0),Vec3(1.0, 1.0, 1.0),Vec3(1.0, 1.0, 1.0)));
        REQUIRE(Mat(Vec3(1.0, 4.0, 7.0), Vec3(2.0, 5.0, 8.0), Vec3(3.0, 6.0, 9.0)) *
        Mat(Vec3(9.0, 6.0, 3.0), Vec3(8.0, 5.0, 2.0), Vec3(7.0, 4.0, 1.0))
        == Mat(Vec3(30.0, 84.0, 138.0),Vec3(24.0, 69.0, 114.0),Vec3(18.0, 54.0, 90.0)));
    }
    SECTION("Normal scalar operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) * 2
        == Mat(Vec3(2.0, 2.0, 2.0),Vec3(2.0, 2.0, 2.0),Vec3(2.0, 2.0, 2.0)));
    }
}


TEST_CASE("Matrix inverse Multiplication and division", "[Mat]") {

    SECTION("Normal operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) /
                Mat(Vec3(1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0), Vec3(0.0, 0.0, 1.0))
                == Mat(Vec3(1.0, 1.0, 1.0),Vec3(1.0, 1.0, 1.0),Vec3(1.0, 1.0, 1.0)));
        REQUIRE(Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)) /
                Mat(Vec3(0.0, 3.0, 2.0), Vec3(-1.0, 2.0, 1.0), Vec3(-3.0, 3.0, 2.0))
                == Mat( Vec3(1.0, 2.0, 3.0), Vec3(-1.0, -2.0, -3.0), Vec3(0.0, 0.0, 0.0)));
    }
    SECTION("Normal scalar operation") {
        REQUIRE(Mat(Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0), Vec3(1.0, 1.0, 1.0)) / 2.0
                == Mat(Vec3(0.5, 0.5, 0.5),Vec3(0.5, 0.5, 0.5),Vec3(0.5, 0.5, 0.5)));
    }

}TEST_CASE("Determinant of a Matrix", "[Mat]"){
    SECTION("Determinant of a singular matrix"){
        REQUIRE(Mat(Vec3(1.0, 4.0, 7.0), Vec3(2.0, 5.0, 8.0), Vec3(3.0, 6.0, 9.0)).calcDet()
        == 0.0);
    }
    SECTION("Determinant of a Nonsingular matrix"){
        REQUIRE(Mat(Vec3(0.0, 3.0, 2.0), Vec3(-1.0, 2.0, 1.0), Vec3(-3.0, 3.0, 2.0)).calcDet()
                == 3.0);
    }
}


TEST_CASE("Transpose a Matrix", "[Mat]"){
    SECTION("Normal operation"){
        REQUIRE(Mat(Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0), Vec3(1.0, 2.0, 3.0)).transpose()
                == Mat(Vec3(1.0,1.0,1.0), Vec3(2.0,2.0,2.0), Vec3(3.0,3.0,3.0)));
    }
}

TEST_CASE("invert a Matrix", "[Mat]"){
    SECTION("Normal operation"){
        REQUIRE(Mat(Vec3(1.0, 0.0, 5.0), Vec3(2.0, 1.0, 6.0), Vec3(3.0, 4.0, 0.0)).inverse()
                == Mat(Vec3(-24.0,20.0,-5.0), Vec3(18.0,-15.0,4.0), Vec3(5.0,-4.0,1.0)));
    }
}