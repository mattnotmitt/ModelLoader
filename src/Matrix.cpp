#include <Vec3.h>
#include <Matrix.h>

//
// Created by Seámus on 09/11/18.
//

/**
 * Mat constructor
 * @param VecA
 * @param VecB
 * @param VecC
 */
Mat::Mat(Vec3 VecA, Vec3 VecB, Vec3 VecC): VecA(VecA), VecB(VecB), VecC(VecC) {}

/**
 * VecA getter
 * @return VecA
 */
const Vec3 &Mat::getVecA() const {
    return VecA;
}

/**
 * VecA setter
 * @param VecA
 */
void Mat::setVecA(const Vec3 &VecA) {
    Mat::VecA = VecA;
}

/**
 * VecB getter
 * @return VecB
 */
const Vec3 &Mat::getVecB() const {
    return VecB;
}
/**
 * VecB setter
 * @param VecB
 */
void Mat::setVecB(const Vec3 &VecB) {
    Mat::VecB = VecB;
}

/**
 * VecC getter
 * @return VecC
 */
const Vec3 &Mat::getVecC() const {
    return VecC;
}

/**
 * vec C setter
 * @param VecC
 */
void Mat::setVecC(const Vec3 &VecC) {
    Mat::VecC = VecC;
}

/**
 * addition of two matrices
 * @param right
 * @return the resultant matrix
 */
Mat Mat::operator+(const Mat &right) {
    return {VecA + right.VecA, VecB + right.VecB, VecC + right.VecC};
}

/**
 * subtraction of two matrices
 * @param right
 * @return the resultant matrix
 */
Mat Mat::operator-(const Mat &right) {
    return {VecA - right.VecA, VecB - right.VecB, VecC - right.VecC};
}

/**
 * Matrix multiplication
 * @param right
 * @return the product of LHS*RHS
 */
Mat Mat::operator*(const Mat &right){

    Vec3 X(right.VecA.getX(), right.VecB.getX(), right.VecC.getX());
    Vec3 Y(right.VecA.getY(), right.VecB.getY(), right.VecC.getY());
    Vec3 Z(right.VecA.getZ(), right.VecB.getZ(), right.VecC.getZ());

    VecA.setX(X.dot(VecA)); // ( - - - )   ( |     )
    VecB.setX(X.dot(VecB)); // (       ) o ( |     )
    VecC.setX(X.dot(VecC)); // (       )   ( |     )

    VecA.setY(Y.dot(VecA));// (       )   (   |   )
    VecB.setY(Y.dot(VecB));// ( - - - ) o (   |   )
    VecC.setY(Y.dot(VecC));// (       )   (   |   )

    VecA.setZ(Z.dot(VecA));// (       )   (      |)
    VecB.setZ(Z.dot(VecB));// (       ) o (      |)
    VecC.setZ(Z.dot(VecC));// ( - - - )   (      |)


    return {VecA, VecB, VecC};
}

/**
 * scalar multiplication of a matrix
 * @param right
 * @return the scalar factored matrix
 */
Mat Mat::operator*(const double &right) {
    return {VecA * right, VecB * right, VecC * right};
}

/**
 * inverse matrix multiplication
 * @param right
 * @return the product of LHS * RHS^-1
 */
Mat Mat::operator/(const Mat &right) {
    return {*this * right.inverse()};
}

/**
 * scalar division of a matrix
 * @param right
 * @return the factored matrix
 */
Mat Mat::operator/(const double &right) {
    return {VecA / right, VecB / right , VecC / right};
}

/**
 * checks if lhs = rhs
 * @param rhs
 * @return true if left and right are the same
 */
bool Mat::operator==(const Mat &rhs) const {
    return VecA == rhs.VecA &&
           VecB == rhs.VecB &&
           VecC == rhs.VecC;
}
/**
 * checks if lhs != rhs
 * @param rhs
 * @return True if left and right are different
 */
bool Mat::operator!=(const Mat &rhs) const {
    return !(rhs == *this);
}

/**
 * Calculates the determinant of a martix
 * @return the determinant
 */
double Mat::calcDet() const{
    double a, b, c, d;
    std::array<double, 3> det{0};

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

    return std::accumulate(det.begin(),det.end(), 0.0);

}
/**
 * transposes a matrix
 * @return the transposed matrix
 */
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

/**
 * inverts a matrix
 * @return the inverted matrix
 */
Mat Mat::inverse() const{
    double Det;
    Mat out = this->transpose();
    Det = out.calcDet();
    out = out.detMatrix();
    out = out.cofactor();
    if (Det!= 0) {
        out = out * (1 / Det);
    }
    else {
        throw;
    }

    return {out};
}

/**
 * creates a matrix of determinants using 2x2 minor matrices
 * @return matrix of determinants
 */
Mat Mat::detMatrix(){
    Mat out;
    double a, b, c, d;
    std::array<double, 9> det{0};

    //------Find X Determinants-------
    a = this->VecB.getY();
    b = this->VecC.getY();
    c = this->VecB.getZ();
    d = this->VecC.getZ();

    det[0] = a*d - b*c;

    a = this->VecA.getY();
    b = this->VecC.getY();
    c = this->VecA.getZ();
    d = this->VecC.getZ();

    det[1] = a*d - b*c;

    a = this->VecA.getY();
    b = this->VecB.getY();
    c = this->VecA.getZ();
    d = this->VecB.getZ();

    det[2] = a*d - b*c;

    //------Find Y Determinants-------

    a = this->VecB.getX();
    b = this->VecC.getX();
    c = this->VecB.getZ();
    d = this->VecC.getZ();

    det[3] = a*d - b*c;

    a = this->VecA.getX();
    b = this->VecC.getX();
    c = this->VecA.getZ();
    d = this->VecC.getZ();

    det[4] = a*d - b*c;

    a = this->VecA.getX();
    b = this->VecB.getX();
    c = this->VecA.getZ();
    d = this->VecB.getZ();

    det[5] = a*d - b*c;

    //------Find Z Determinants-------

    a = this->VecB.getX();
    b = this->VecC.getX();
    c = this->VecB.getY();
    d = this->VecC.getY();

    det[6] = a*d - b*c;

    a = this->VecA.getX();
    b = this->VecC.getX();
    c = this->VecA.getY();
    d = this->VecC.getY();

    det[7] = a*d - b*c;

    a = this->VecA.getX();
    b = this->VecB.getX();
    c = this->VecA.getY();
    d = this->VecB.getY();

    det[8] = a*d - b*c;

    //------Populate for output-------
    out.populate(det[0],det[1],det[2],
                 det[3],det[4],det[5],
                 det[6],det[7],det[8]);
    return out;
}

/**
 * creates cofactor matrix from current matrix
 * |+ - + |
 * |- + - |
 * |+ - + |
 * @return cofactor matrix
 */
Mat Mat::cofactor(){
    Mat out = *this;
    out.VecA.setY(this->VecA.getY()* -1);
    out.VecB.setX(this->VecB.getX()* -1);
    out.VecB.setZ(this->VecB.getZ()* -1);
    out.VecC.setY(this->VecC.getY()* -1);
    return out;
}

/**
 *  Generate Array of Rotation Matrices x, y, z
 * @param xRads
 * @param yRads
 * @param zRads
 * @return Array{X Rotation matrix, Y Rotation matrix, Z Rotation matrix}
 */
std::array<Mat, 3> genRotation(double xRads, double yRads, double zRads) {
    std::array<Mat, 3>Rotation;
    Rotation[0].populate(1, 0, 0, 0, std::cos(xRads), std::sin(xRads), 0, -std::sin(xRads), std::cos(xRads));
    Rotation[1].populate(std::cos(yRads), 0, -std::sin(yRads), 0, 1, 0, std::sin(yRads), 0, std::cos(yRads));
    Rotation[2].populate(std::cos(zRads), std::sin(zRads), 0, -std::sin(zRads), std::cos(zRads), 0, 0, 0, 1);

    return Rotation;
}

/**
 * fills a matrix with 9 arguments
 * @param a
 * @param b
 * @param c
 * @param d
 * @param e
 * @param f
 * @param g
 * @param h
 * @param i
 */
void Mat::populate(double a, double b, double c,
                double d, double e, double f,
                double g, double h, double i){
    this->VecA.setX(a);
    this->VecB.setX(b);
    this->VecC.setX(c);
    this->VecA.setY(d);
    this->VecB.setY(e);
    this->VecC.setY(f);
    this->VecA.setZ(g);
    this->VecB.setZ(h);
    this->VecC.setZ(i);
}

/**
 * stream output for displaying a matrix
 * @param os
 * @param Mat
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Mat& Mat)
{
    Vec3 X(Mat.VecA.getX(), Mat.VecB.getX(), Mat.VecC.getX());
    Vec3 Y(Mat.VecA.getY(), Mat.VecB.getY(), Mat.VecC.getY());
    Vec3 Z(Mat.VecA.getZ(), Mat.VecB.getZ(), Mat.VecC.getZ());

    os  << X.getX() << ',' << X.getY() << ',' << X.getZ() <<std::endl;
    os  << Y.getX() << ',' << Y.getY() << ',' << Y.getZ() <<std::endl;
    os  << Z.getX() << ',' << Z.getY() << ',' << Z.getZ() <<std::endl;
    return os;
}

