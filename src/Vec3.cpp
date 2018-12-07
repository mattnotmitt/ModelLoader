//
// Created by matt on 08/11/18.
//

#include "Vec3.h"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3::Vec3(double x, double y, double z, int index) : x(x), y(y), z(z), index(index) {}


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

int Vec3::getIndex() const {
    return index;
}

void Vec3::setIndex(int index) {
    Vec3::index = index;
}


Vec3 Vec3::operator+(const Vec3 &right) {
    return {x + right.x, y + right.y, z + right.z};
}


Vec3 Vec3::operator-(const Vec3 &right) {
    return {x - right.x, y - right.y, z - right.z};
}

Vec3 Vec3::operator*(const double &right) {
    return {x * right, y * right, z * right};
}

Vec3 Vec3::operator*(const Vec3 &right) {
    return {y * right.z - z * right.y,
            z * right.x - x * right.z,
            x * right.y - y * right.x};
}

Vec3 Vec3::operator/(const double &right) {
    return {x / right, y / right, z / right};
}

bool Vec3::operator==(const Vec3 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool Vec3::operator!=(const Vec3 &rhs) const {
    return !(rhs == *this);
}


double Vec3::dot(const Vec3 &right) {
    return x*right.x + y*right.y + z*right.z;
}

double Vec3::mag(){
    return sqrt(x*x + y*y + z*z);
}


std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    os << std::fixed << std::setprecision(3) <<'[' << vec.getX() << ',' << vec.getY() << ',' << vec.getZ() << ']';
    return os;
}

std::ofstream& operator<<(std::ofstream& os, const Vec3& vec) {
    //TODO: Output vector to look like input file
    return os;
};

std::istream &operator>>(std::istream &is, Vec3 &vec) {
    double x, y, z;
    is >> x >> y >> z;

    vec.setX(x);
    vec.setY(y);
    vec.setZ(z);

    return is;
}
