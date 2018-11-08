//
// Created by matt on 08/11/18.
//

#pragma once

class Vec3 {
private:
    float x;
    float y;
    float z;
public:
    Vec3() : x(0), y(0), z(0) {};
    Vec3(float x, float y, float z);

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    Vec3 operator+(const Vec3& right);
    Vec3 operator-(const Vec3& right);
    Vec3 operator*(const Vec3& right);
    Vec3 operator/(const Vec3& right);
};
