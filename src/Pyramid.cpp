//
// Created by matt on 08/11/18.
//

#include "Pyramid.h"

Pyramid::Pyramid() {
    this->CellType = Cell::Type::PYRAMID;
}

Pyramid::Pyramid(std::shared_ptr<Material> CellMaterial, int CellIndex) : Cell(CellMaterial, CellIndex) {
    this->CellType = Cell::Type::PYRAMID;
}

Pyramid::Pyramid(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial)
        : Cell(CellVertices, CellMaterial) {
    this->CellType = Cell::Type::PYRAMID;
}

double Pyramid::calcVolume() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    double volume;
    Vec3 A = *vertices[0] - *vertices[1]; //VectA
    Vec3 B = *vertices[0] - *vertices[3]; //VectB
    Vec3 C = *vertices[0] - *vertices[4]; //VectC
    volume = std::abs((A*B).dot(C)) * (1.0/3.0);
    return volume;
}

Vec3 Pyramid::calcCentreofGravity() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    Vec3 cog;
    Vec3 Sum = *vertices[0] + *vertices[1] + *vertices[2] + *vertices[3] + *vertices[4];
    cog = Sum / 5.0;
    return cog;
}

double Pyramid::calcWeight() const {
    const Material material = *getCellMaterial();
    const double volume = getVolume();
    double weight = 0;
    weight = material.getDensity() * volume;
    return weight;
}
