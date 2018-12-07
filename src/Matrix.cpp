#include <Vec3.h>
#include <Matrix.h>

//
// Created by Seámus on 09/11/18.
//

Mat::Mat(Vec3 VecA, Vec3 VecB, Vec3 VecC): VecA(VecA), VecB(VecB), VecC(VecC) {}

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

Mat Mat::operator*(const double &right) {

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

Mat Mat::operator/(const double &right) {

    VecA / right;
    VecB / right;
    VecC / right;

    return {VecA, VecB, VecC};
}

bool Mat::operator==(const Mat &rhs) const {
    return VecA == rhs.VecA &&
           VecB == rhs.VecB &&
           VecC == rhs.VecC;
}

bool Mat::operator!=(const Mat &rhs) const {
    return !(rhs == *this);
}

double Mat::calcDet() const{
    double a, b, c, d;
    std::array<double, 9> det{0};

    a = this->VecB.getY();
    b = this->VecC.getY();
    c = this->VecB.getZ();
    d = this->VecC.getZ();

    det[0] = a*d - b*c;
    det[0]= det[0]*this->VecA.getX();

    a = this->VecA.getY();
    b = this->VecC.getY();
    c = this->VecA.getZ();
    d = this->VecC.getZ();

    det[1] = a*d - b*c;
    det[1]= (-1)*det[1]*this->VecB.getX();

    a = this->VecA.getY();
    b = this->VecB.getY();
    c = this->VecA.getZ();
    d = this->VecB.getZ();

    det[2] = a*d - b*c;
    det[2] = det[2]*this->VecC.getX();

    /*//----------------------

    a = this->VecB.getX();
    b = this->VecC.getX();
    c = this->VecB.getZ();
    d = this->VecC.getZ();

    det[3] = a*d - b*c;
    det[3] = (-1)*det[3]*this->VecA.getY();

    a = this->VecA.getX();
    b = this->VecC.getX();
    c = this->VecA.getZ();
    d = this->VecC.getZ();

    det[4] = a*d - b*c;
    det[4] = det[4]*this->VecB.getY();

    a = this->VecA.getX();
    b = this->VecB.getX();
    c = this->VecA.getZ();
    d = this->VecB.getZ();

    det[5] = a*d - b*c;
    det[5] = (-1)*det[5]*this->VecC.getY();

    //-----------------------

    a = this->VecB.getX();
    b = this->VecC.getX();
    c = this->VecB.getY();
    d = this->VecC.getY();

    det[6] = a*d - b*c;
    det[6] = det[6]*this->VecA.getZ();

    a = this->VecA.getX();
    b = this->VecC.getX();
    c = this->VecA.getY();
    d = this->VecC.getY();

    det[7] = a*d - b*c;
    det[7] = (-1)*det[7]*this->VecB.getZ();

    a = this->VecA.getX();
    b = this->VecB.getX();
    c = this->VecA.getY();
    d = this->VecB.getY();

    det[8] = a*d - b*c;
    det[8] = det[8]*this->VecC.getZ();*/

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
    if (Det!= 0) {
        out = out / Det;
    }
    else {
        throw;
    }

    return {out};

}

std::ostream& operator<<(std::ostream& os, const Mat& Mat)
{ /*
    Vec3 X(Mat.VecA.getX(), Mat.VecB.getX(), Mat.VecC.getX());
    Vec3 Y(Mat.VecA.getY(), Mat.VecB.getY(), Mat.VecC.getY());
    Vec3 Z(Mat.VecA.getZ(), Mat.VecB.getZ(), Mat.VecC.getZ());

    os << '/' << X.getX() << ',' << X.getY() << ',' << X.getZ() << '\\'<<std::endl;
    os << '|' << Y.getX() << ',' << Y.getY() << ',' << Y.getZ() << '|'<<std::endl;
    os << '\\' << Z.getX() << ',' << Z.getY() << ',' << Z.getZ() << '/'<<std::endl;*/
    os << "[ " << Mat.VecA << ", " << Mat.VecB << ", " << Mat.VecC << " ]" << std::endl;
    return os;
}

