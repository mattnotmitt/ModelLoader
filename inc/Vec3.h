//
// Created by matt on 08/11/18.
//

#pragma once

#include <iostream>
#include "catch.hpp"

class Vec3 {
private:
    double x;
    double y;
    double z;
public:
    Vec3() : x(0), y(0), z(0) {};

    Vec3(double x, double y, double z);

    bool operator==(const Vec3 &rhs) const;
    bool operator!=(const Vec3 &rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec);

    friend std::istream &operator>>(std::istream &is, Vec3 &vec);

    double getX() const;

    double getY() const;

    double getZ() const;

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    Vec3 operator+(const Vec3& right);
    Vec3 operator-(const Vec3& right);
    Vec3 operator*(const Vec3& right);
    Vec3 operator/(const Vec3& right);
};
