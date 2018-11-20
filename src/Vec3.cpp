//
// Created by matt on 08/11/18.
//

#include "Vec3.h"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3 &right) {
    return {x + right.x, y + right.y, z + right.z};
}

Vec3 Vec3::operator-(const Vec3 &right) {
    return {x - right.x, y - right.y, z - right.z};
}

Vec3 Vec3::operator*(const Vec3 &right) {
    // TODO: Multiply two Vec3s
    return {};
}

Vec3 Vec3::operator/(const Vec3 &right) {
    // TODO: Divide two Vec3s
    return {};
}

double Vec3::getX() const {
    return x;
}

void Vec3::setX(double x) {
    Vec3::x = x;
}

double Vec3::getY() const {
    return y;
}

void Vec3::setY(double y) {
    Vec3::y = y;
}

double Vec3::getZ() const {
    return z;
}

void Vec3::setZ(double z) {
    Vec3::z = z;
}

bool Vec3::operator==(const Vec3 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool Vec3::operator!=(const Vec3 &rhs) const {
    return !(rhs == *this);
}

std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    os << '[' << vec.getX() << ',' << vec.getY() << ',' << vec.getZ() << ']';
    return os;
}

std::istream &operator>>(std::istream &is, Vec3 &vec) {
    double x, y, z;
    is >> x >> y >> z;

    vec.setX(x);
    vec.setY(y);
    vec.setZ(z);

    return is;
}

TEST_CASE( "Vec3 Addition", "[Vec3]" ) {
    SECTION("Default vectors") {
        REQUIRE(Vec3() + Vec3() == Vec3());
    }
    SECTION("Default vectors + instantiated vectors") {
        REQUIRE(Vec3(1, 2, 3) + Vec3() == Vec3(1, 2, 3));
        REQUIRE(Vec3() + Vec3(1, 2, 3) == Vec3(1, 2, 3));
        REQUIRE(Vec3(0,0,0) + Vec3(0,0,0) == Vec3());
    }
    SECTION("Normal operation") {
        REQUIRE(Vec3(1, 1, 1) + Vec3(1, 1, 1) == Vec3(2, 2, 2));
    }
}

TEST_CASE( "Vec3 Subtraction", "[Vec3]" ) {
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