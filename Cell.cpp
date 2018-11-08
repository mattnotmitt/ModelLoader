//
// Created by matt on 08/11/18.
//

#include "Cell.h"

Cell::Cell(vector<Vector3D> CellVertices, Material CellMaterial)
    : CellVertices(move(CellVertices)), CellMaterial(CellMaterial) {};

const vector<Vector3D> &Cell::getCellVertices() const {
    return CellVertices;
}

void Cell::setCellVertices(const vector<Vector3D> &CellVertices) {
    Cell::CellVertices = CellVertices;
}

float Cell::getVolume() const {
    return Volume;
}

void Cell::setVolume(float Volume) {
    Cell::Volume = Volume;
}

const Vector3D &Cell::getCentreOfGravity() const {
    return CentreOfGravity;
}

void Cell::setCentreOfGravity(const Vector3D &CentreOfGravity) {
    Cell::CentreOfGravity = CentreOfGravity;
}

float Cell::getWeight() const {
    return Weight;
}

void Cell::setWeight(float Weight) {
    Cell::Weight = Weight;
}

const Material &Cell::getCellMaterial() const {
    return CellMaterial;
}

void Cell::setCellMaterial(const Material &material) {
    Cell::CellMaterial = material;
}
