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

Mat Mat::operator*(const Mat &right) {
    Vec3 X(VecA.getX(), VecB.getX(), VecC.getX());
    Vec3 Y(VecA.getY(), VecB.getY(), VecC.getY());
    Vec3 Z(VecA.getZ(), VecB.getZ(), VecC.getZ());

    VecA.setX(X*right.VecA);
    VecB.setX(X*right.VecB);
    VecC.setX(X*right.VecC);

    VecA.setY(Y*right.VecA);
    VecB.setY(Y*right.VecB);
    VecC.setY(Y*right.VecC);

    VecA.setZ(Z*right.VecA);
    VecB.setZ(Z*right.VecB);
    VecC.setZ(Z*right.VecC);

    return {VecA, VecB, VecC};
}

Mat Mat::operator*(const float &right) {
    Vec3 X(VecA.getX(), VecB.getX(), VecC.getX());
    Vec3 Y(VecA.getY(), VecB.getY(), VecC.getY());
    Vec3 Z(VecA.getZ(), VecB.getZ(), VecC.getZ());

    VecA.setX(X*right.VecA);
    VecB.setX(X*right.VecB);
    VecC.setX(X*right.VecC);

    VecA.setY(Y*right.VecA);
    VecB.setY(Y*right.VecB);
    VecC.setY(Y*right.VecC);

    VecA.setZ(Z*right.VecA);
    VecB.setZ(Z*right.VecB);
    VecC.setZ(Z*right.VecC);

    return {VecA, VecB, VecC};
}

Mat Mat::operator/(const Mat &right) {
    // TODO: Divide two Mats
    return {};
}

float Mat::calcDet(){
    float a, b, c, d;
    float det1, det2, det3, det4, det5, det6, det7, det8, det9;

    a = VecB.getY();
    b = VecC.getY();
    c = VecB.getZ();
    d = VecC.getZ();

    det1 = a*d - b*c;
    det1= det1*VecA.getX();

    a = VecA.getY();
    b = VecC.getY();
    c = VecA.getZ();
    d = VecC.getZ();

    det2 = a*d - b*c;
    det2= (-1)*det2*VecB.getX();

    a = VecA.getY();
    b = VecB.getY();
    c = VecA.getZ();
    d = VecB.getZ();

    det3 = a*d - b*c;
    det3 = det3*VecB.getX();

    //----------------------

    a = VecB.getX();
    b = VecC.getX();
    c = VecB.getZ();
    d = VecC.getZ();

    det4 = a*d - b*c;
    det4 = (-1)*det4*VecA.getY();

    a = VecA.getX();
    b = VecC.getX();
    c = VecA.getZ();
    d = VecC.getZ();

    det5 = a*d - b*c;
    det5 = det5*VecB.getY();

    a = VecA.getX();
    b = VecB.getX();
    c = VecA.getZ();
    d = VecB.getZ();

    det6 = a*d - b*c;
    det6 = (-1)*det6*VecB.getY();

    //-----------------------

    a = VecB.getX();
    b = VecC.getX();
    c = VecB.getY();
    d = VecC.getY();

    det7 = a*d - b*c;
    det7 = det7*VecA.getZ();

    a = VecA.getX();
    b = VecC.getX();
    c = VecA.getY();
    d = VecC.getY();

    det8 = a*d - b*c;
    det8 = (-1)*det8*VecB.getZ();

    a = VecA.getX();
    b = VecB.getX();
    c = VecA.getY();
    d = VecB.getY();

    det9 = a*d - b*c;
    det9 = det9*VecB.getZ();

    return {det1 + det2 + det3 + det4 + det5 + det6 + det7 + det7 + det8 + det9};

}

Mat Mat::inverse(){
    float Det = calcDet();
    float temp;

    temp = VecB.getX();
    VecB.setX(VecA.getY());
    VecA.setY(temp);

    temp = VecC.getX();
    VecC.setX(VecA.getZ());
    VecA.setZ(temp);

    temp = VecC.getY();
    VecC.setY(VecB.getZ());
    VecB.setZ(temp);





}
