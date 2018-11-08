//
// Created by matt on 08/11/18.
//

#include "Cell.h"

Cell::Cell(std::vector<Vec3> CellVertices, Material CellMaterial)
    : CellVertices(std::move(CellVertices)), CellMaterial(CellMaterial) {};

const std::vector<Vec3> &Cell::getCellVertices() const {
    return CellVertices;
}

void Cell::setCellVertices(const std::vector<Vec3> &CellVertices) {
    Cell::CellVertices = CellVertices;
}

float Cell::getVolume() const {
    return Volume;
}

void Cell::setVolume(float Volume) {
    Cell::Volume = Volume;
}

const Vec3 &Cell::getCentreOfGravity() const {
    return CentreOfGravity;
}

void Cell::setCentreOfGravity(const Vec3 &CentreOfGravity) {
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
