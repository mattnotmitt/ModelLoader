//
// Created by matt on 08/11/18.
//

#include "Vec3.h"
/**
 * Vec3 Constructor
 * @param x
 * @param y
 * @param z
 */
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
Vec3::Vec3(double x, double y, double z, int index) : x(x), y(y), z(z), index(index) {}

/**
 * X getter
 * @return X
 */
double Vec3::getX() const {
    return x;
}

/**
 * X Setter
 * @param x
 */
void Vec3::setX(double x) {
    Vec3::x = x;
}

/**
 * Y Getter
 * @return
 */
double Vec3::getY() const {
    return y;
}

/**
 * Y Setter
 * @param y
 */
void Vec3::setY(double y) {
    Vec3::y = y;
}

/**
 * Z Getter
 * @return
 */
double Vec3::getZ() const {
    return z;
}

/**
 * Z Setter
 * @param z
 */
void Vec3::setZ(double z) {
    Vec3::z = z;
}

/**
 * Addition of two Vec3s
 * @param right
 * @return the resultant vector
 */
Vec3 Vec3::operator+(const Vec3 &right) {
    return {x + right.x, y + right.y, z + right.z};
}

/**
 * Subtraction of two Vec3s
 * @param right
 * @return
 */
Vec3 Vec3::operator-(const Vec3 &right) {
    return {x - right.x, y - right.y, z - right.z};
}

/**
 * Cross product of two Vec3s
 * @param right
 * @return Cross product
 */
Vec3 Vec3::operator*(const Vec3 &right) {
    return {y * right.z - z * right.y,
            z * right.x - x * right.z,
            x * right.y - y * right.x};
}

/**
 * Multiplication of a Vec3 by a scalar
 * @param right
 * @return scalar factored vector
 */
Vec3 Vec3::operator*(const double &right) {
    return {x * right, y * right, z * right};
}

/**
 * Division of a Vec3 by a scalar
 * @param right
 * @return vector factored by a scalar
 */
Vec3 Vec3::operator/(const double &right) {
    return {x / right, y / right, z / right};
}

/**
 * checks if lhs = rhs
 * @param rhs
 * @return true if lhs and rhs are the same
 */
bool Vec3::operator==(const Vec3 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

/**
 * checks if lhs != rhs
 * @param rhs
 * @return true if lhs and rhs are different
 */
bool Vec3::operator!=(const Vec3 &rhs) const {
    return !(rhs == *this);
}

/**
 * Dot (Scalar) product of two Vec3s
 * @param right
 * @return Scalar product
 */
double Vec3::dot(const Vec3 &right) {
    return x*right.x + y*right.y + z*right.z;
}

/**
 * calculates the magnitude of a vector
 * @return magnitude
 */
double Vec3::mag(){
    return sqrt(x*x + y*y + z*z);
}

/**
 * stream output for displaying vectors
 * @param os
 * @param vec
 * @return
 */
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

int Vec3::getIndex() const {
    return index;
}

void Vec3::setIndex(int index) {
    Vec3::index = index;
}
