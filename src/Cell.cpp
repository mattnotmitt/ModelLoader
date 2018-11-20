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

const Material &Cell::getCellMaterial() const {
    return CellMaterial;
}

void Cell::setCellMaterial(const Material &material) {
    Cell::CellMaterial = material;
}

float Cell::getVolume() const {
    return this->calcVolume();
}

const Vec3 Cell::getCentreOfGravity() const {
    return this->calcCentreofGravity();
}

float Cell::getWeight() const {
    return this->calcWeight();
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "Made of material " << cell.getCellMaterial().getName() << " and has " << cell.getCellVertices().size()
       << " vertices.";
    return os;
};
