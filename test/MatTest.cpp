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
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)) + Mat()
        == Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)));
        REQUIRE(Mat() + Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3))
        == Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)));
        REQUIRE(Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) +
        Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) == Mat()));
    }
    SECTION("Normal operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) +
        Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1))
        == Mat(Vec3(2, 2, 2),Vec3(2, 2, 2),Vec3(2, 2, 2)));
    }
}

TEST_CASE("Mat Subtraction", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() - Mat() == Mat());
    }
    SECTION("Default vectors - instantiated vectors") {
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)) - Mat()
        == Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)));
        REQUIRE(Mat() - Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3))
        == Mat(Vec3(-1, -2, -3), Vec3(-1, -2, -3), Vec3(-1, -2, -3)));
        REQUIRE(Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) -
        Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) == Mat()));
    }
    SECTION("Normal operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) -
        Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1))
        == Mat();
    }
}

TEST_CASE("Mat Multiplication", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() * Mat() == Mat());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)) * Mat()
        == Mat());
        REQUIRE(Mat() * Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3))
        == Mat());
        REQUIRE(Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) *
        Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) == Mat()));
    }
    SECTION("Normal 2 Matrices operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) *
        Mat(Vec3(1, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, 1))
        == Mat(Vec3(1, 1, 1),Vec3(1, 1, 1),Vec3(1, 1, 1)));
        REQUIRE(Mat(Vec3(1, 4, 7), Vec3(2, 5, 8), Vec3(3, 6, 9)) *
        Mat(Vec3(9, 6, 3), Vec3(8, 5, 2), Vec3(7, 4, 1))
        == Mat(Vec3(30, 84, 138),Vec3(24, 69, 144),Vec3(18, 54, 90)));
    }
    SECTION("Normal scalar operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) * 2
        == Mat(Vec3(2, 2, 2),Vec3(2, 2, 2),Vec3(2, 2, 2)));
    }

}

TEST_CASE("Matrix inverse Multiplication", "[Mat]") {
    SECTION("Default Matrices") {
        REQUIRE(Mat() / Mat() == Mat());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)) / Mat()
                == Mat());
        REQUIRE(Mat() / Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3))
                == Mat());
        REQUIRE(Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) /
                Mat(Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0)) == Mat()));
    }
    SECTION("Normal 2 Matrices operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) /
                Mat(Vec3(1, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, 1))
                == Mat(Vec3(1, 1, 1),Vec3(1, 1, 1),Vec3(1, 1, 1)));
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3)) /
                Mat(Vec3(1, 1, 0), Vec3(1, 0, 1), Vec3(0, 1, 0)
                == Mat(Vec3(0, 0, 0), Vec3(1, 2, 3), Vec3(1, 2, 3)));
    }
    SECTION("Normal scalar operation") {
        REQUIRE(Mat(Vec3(1, 1, 1), Vec3(1, 1, 1), Vec3(1, 1, 1)) / 2
                == Vec3(0.5, 0.5, 0.5),Vec3(0.5, 0.5, 0.5),Vec3(0.5, 0.5, 0.5)));
    }

}

TEST_CASE("Determinant of a Matrix", "[Mat]"){
    SECTION("Determinant of a singular matrix"){
        REQUIRE(Mat(Vec3(1, 4, 7), Vec3(2, 5, 8), Vec3(3, 6, 9)).calcDet()
        == 0);
    }
    SECTION("Determinant of a Nonsingular matrix"){
        REQUIRE(Mat(Vec3(0, 3, 2), Vec3(-1, 2, 1), Vec3(-3, 3, 2)).calcDet()
                == 3);
    }
}

TEST_CASE("Transpose a Matrix", "[Mat]"){
    SECTION("Normal operation"){
        REQUIRE(Mat(Vec3(1, 2, 3), Vec3(1, 2, 3), Vec3(1, 2, 3))
                == 0);
    }
}