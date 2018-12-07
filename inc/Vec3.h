//
// Created by matt on 08/11/18.
//

#pragma once

#include <iomanip>
#include <iostream>

class Vec3 {
private:
    int index = -1;
    double x;
    double y;
    double z;
public:
    Vec3() : x(0), y(0), z(0) {};
    Vec3(double x, double y, double z);
    Vec3(double x, double y, double z, int index);

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Vec3& vec);

    friend std::istream &operator>>(std::istream &is, Vec3 &vec);

    double getX() const;
    double getY() const;
    double getZ() const;
    int getIndex() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setIndex(int index);


    Vec3 operator+(const Vec3& right);
    Vec3 operator-(const Vec3& right);
    Vec3 operator*(const double& right);
    Vec3 operator*(const Vec3& right);
    Vec3 operator/(const double& right);
    bool operator==(const Vec3 &rhs) const;
    bool operator!=(const Vec3 &rhs) const;

    double dot(const Vec3 &right);

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec);
    friend std::istream &operator>>(std::istream &is, Vec3 &vec);
};
