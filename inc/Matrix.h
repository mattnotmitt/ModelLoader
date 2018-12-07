//
// Created by Seámus on 09/11/18.
//
#pragma once

#include <numeric>
#include <array>
#include "Vec3.h"

class Mat {
private:
    Vec3 VecA;
    Vec3 VecB;
    Vec3 VecC;
public:
    Mat() : VecA(), VecB(), VecC() {};
    Mat(Vec3 VecA, Vec3 VecB, Vec3 VecC);

    friend std::ostream& operator<<(std::ostream& os, const Mat& Mat);

    const Vec3 &getVecA() const;
    void setVecA(const Vec3 &VecA);

    const Vec3 &getVecB() const;
    void setVecB(const Vec3 &VecB);

    const Vec3 &getVecC() const;
    void setVecC(const Vec3 &VecC);

    Mat operator+ (const Mat& right);
    Mat operator-(const Mat& right);
    Mat operator*(const Mat& right);
    Mat operator*(const double& right);
    Mat operator/(const Mat& right);
    Mat operator/(const double& right);
    bool operator==(const Mat &rhs) const;
    bool operator!=(const Mat &rhs) const;

    double calcDet() const;
    Mat inverse() const;
    Mat transpose() const;





};
