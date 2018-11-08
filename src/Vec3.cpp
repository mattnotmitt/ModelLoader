//
// Created by matt on 08/11/18.
//

#include <Vec3.h>

#include "Vec3.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3 &right) {
    return {x + right.x, y + right.y, z + right.z};
}

Vec3 Vec3::operator-(const Vec3 &right) {
    // TODO: Subtract two Vec3s
    return {};
}

Vec3 Vec3::operator*(const Vec3 &right) {
    // TODO: Multiply two Vec3s
    return {};
}

Vec3 Vec3::operator/(const Vec3 &right) {
    // TODO: Divide two Vec3s
    return {};
}

float Vec3::getX() const {
    return x;
}

void Vec3::setX(float x) {
    Vec3::x = x;
}

float Vec3::getY() const {
    return y;
}

void Vec3::setY(float y) {
    Vec3::y = y;
}

float Vec3::getZ() const {
    return z;
}

void Vec3::setZ(float z) {
    Vec3::z = z;
}


#pragma clang diagnostic pop