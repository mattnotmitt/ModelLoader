#include <Vec3.h>
#include <Matrix.h>

//
// Created by Seámus on 09/11/18.
//


const Vec3 &Mat::getVecA() const {
    return VecA;
}

void Mat::setVecA(const Vec3 &VecA) {
    Mat::VecA = VecA;
}

const Vec3 &Mat::getVecB() const {
    return VecB;
}

void Mat::setVecB(const Vec3 &VecB) {
    Mat::VecB = VecB;
}

const Vec3 &Mat::getVecC() const {
    return VecC;
}

void Mat::setVecC(const Vec3 &VecC) {
    Mat::VecC = VecC;
}

Mat Mat::operator+(const Mat &right) {
    return {VecA + right.VecA, VecB + right.VecB, VecC + right.VecC};
}

Mat Mat::operator-(const Mat &right) {
    return {VecA - right.VecA, VecB - right.VecB, VecC - right.VecC};
}

Mat Mat::operator*(const Mat &right){

    Vec3 X(VecA.getX(), VecB.getX(), VecC.getX());
    Vec3 Y(VecA.getY(), VecB.getY(), VecC.getY());
    Vec3 Z(VecA.getZ(), VecB.getZ(), VecC.getZ());

    VecA.setX(X.dot(right.VecA));
    VecB.setX(X.dot(right.VecB));
    VecC.setX(X.dot(right.VecC));

    VecA.setY(Y.dot(right.VecA));
    VecB.setY(Y.dot(right.VecB));
    VecC.setY(Y.dot(right.VecC));

    VecA.setZ(Z.dot(right.VecA));
    VecB.setZ(Z.dot(right.VecB));
    VecC.setZ(Z.dot(right.VecC));


    return {VecA, VecB, VecC};
}

Mat Mat::operator*(const float &right) {

    VecA * right;
    VecB * right;
    VecC * right;

    return {VecA, VecB, VecC};
}

Mat Mat::operator/(const Mat &right) {
    Mat invRight;
    invRight = right.inverse();

    return {*this * invRight};
}

Mat Mat::operator/(const float &right) {

    VecA / right;
    VecB / right;
    VecC / right;

    return {VecA, VecB, VecC};
}

double Mat::calcDet() const{
    double a, b, c, d;
    std::array<double, 9> det{0};

    a = VecB.getY();
    b = VecC.getY();
    c = VecB.getZ();
    d = VecC.getZ();

    det[0] = a*d - b*c;
    det[0]= det[0]*VecA.getX();

    a = VecA.getY();
    b = VecC.getY();
    c = VecA.getZ();
    d = VecC.getZ();

    det[1] = a*d - b*c;
    det[1]= (-1)*det[1]*VecB.getX();

    a = VecA.getY();
    b = VecB.getY();
    c = VecA.getZ();
    d = VecB.getZ();

    det[2] = a*d - b*c;
    det[2] = det[2]*VecB.getX();

    //----------------------

    a = VecB.getX();
    b = VecC.getX();
    c = VecB.getZ();
    d = VecC.getZ();

    det[3] = a*d - b*c;
    det[3] = (-1)*det[3]*VecA.getY();

    a = VecA.getX();
    b = VecC.getX();
    c = VecA.getZ();
    d = VecC.getZ();

    det[4] = a*d - b*c;
    det[4] = det[4]*VecB.getY();

    a = VecA.getX();
    b = VecB.getX();
    c = VecA.getZ();
    d = VecB.getZ();

    det[5] = a*d - b*c;
    det[5] = (-1)*det[5]*VecB.getY();

    //-----------------------

    a = VecB.getX();
    b = VecC.getX();
    c = VecB.getY();
    d = VecC.getY();

    det[6] = a*d - b*c;
    det[6] = det[6]*VecA.getZ();

    a = VecA.getX();
    b = VecC.getX();
    c = VecA.getY();
    d = VecC.getY();

    det[7] = a*d - b*c;
    det[7] = (-1)*det[7]*VecB.getZ();

    a = VecA.getX();
    b = VecB.getX();
    c = VecA.getY();
    d = VecB.getY();

    det[8] = a*d - b*c;
    det[8] = det[8]*VecB.getZ();

    return std::accumulate(det.begin(),det.end(), 0.0);

}

Mat Mat::transpose() const{
    Mat out = *this;

    out.VecB.setX(this->VecA.getY());
    out.VecA.setY(this->VecB.getX());

    out.VecC.setX(this->VecA.getZ());
    out.VecA.setZ(this->VecC.getX());

    out.VecC.setY(this->VecB.getZ());
    out.VecB.setZ(this->VecC.getY());

    return {out};

}

Mat Mat::inverse() const{
    double Det = calcDet();
    Mat out = this->transpose();
    out = out * Det;
    return {out};

}
