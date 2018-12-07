#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-pass-by-value"
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
//
// Created by matt on 08/11/18.
//

#include "Cell.h"

Cell::Cell(std::shared_ptr<Material> material, int index) : CellMaterial(material), index(index) {};

Cell::Cell(std::vector<std::shared_ptr<Vec3>> CellVertices, std::shared_ptr<Material> CellMaterial)
    : CellVertices(CellVertices), CellMaterial(CellMaterial), CellType(Cell::Type::NONE) {};

const std::vector<std::shared_ptr<Vec3>> & Cell::getCellVertices() const {
    return CellVertices;
}

void Cell::setCellVertices(const std::vector<std::shared_ptr<Vec3>> &CellVertices) {
    Cell::CellVertices = CellVertices;
}

const std::shared_ptr<Material> & Cell::getCellMaterial() const {
    return CellMaterial;
}

void Cell::setCellMaterial(const std::shared_ptr<Material> &material) {
    Cell::CellMaterial = material;
}

double Cell::getVolume() const {
    return this->calcVolume();
}

const Vec3 Cell::getCentreOfGravity() const {
    return this->calcCentreofGravity();
}

double Cell::getWeight() const {
    return this->calcWeight();
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    std::map<Cell::Type, std::string> CellString {
        {Cell::Type::TETRAHEDRON, "Tetrahedron"},
        {Cell::Type::PYRAMID, "Pyramid"},
        {Cell::Type::HEXAHEDRON, "Hexahedron"}
    };
    os << "Cell " << cell.getIndex() << " is a " << CellString[cell.CellType]
        << ", made of material " << cell.getCellMaterial()->getName()
        << " and has " << cell.getCellVertices().size() 
        << " vertices. Its volume is " << cell.getVolume() << ", weight is " << cell.getWeight()
        << " and centre of gravity is at " << cell.getCentreOfGravity();
    return os;
};

std::ofstream &operator<<(std::ofstream &os, const Cell &cell) {
    std::map<Cell::Type, std::string> CellString {
            {Cell::Type::TETRAHEDRON, "t"},
            {Cell::Type::PYRAMID, "p"},
            {Cell::Type::HEXAHEDRON, "h"}
    };
    //TODO: output like cell lines in input file
    return os;
}

int Cell::getIndex() const {
    return index;
}

void Cell::setIndex(int index) {
    Cell::index = index;
}

#pragma clang diagnostic pop