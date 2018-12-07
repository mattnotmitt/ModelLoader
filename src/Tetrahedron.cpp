//
// Created by matt on 08/11/18.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron() {
    this->CellType = Cell::Type::TETRAHEDRON;
}

Tetrahedron::Tetrahedron(std::shared_ptr<Material> CellMaterial, int CellIndex) : Cell(CellMaterial, CellIndex) {
    this->CellType = Cell::Type::TETRAHEDRON;
}

Tetrahedron::Tetrahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial)
        : Cell(CellVertices, CellMaterial) {
    this->CellType = Cell::Type::TETRAHEDRON;
}

double Tetrahedron::calcVolume() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    double volume;
    Vec3 magnitude;
    magnitude = (*vertices[0] * *vertices[1]);
    volume = magnitude.dot(*vertices[2])/6;
    return volume;
}

Vec3 Tetrahedron::calcCentreofGravity() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    Vec3 cog;
    cog = (*vertices[0]+*vertices[1]+*vertices[2]+*vertices[3])/5.0;
    return cog;
}

double Tetrahedron::calcWeight() const {
    const Material material = *getCellMaterial();
    const double volume = getVolume();
    float weight = 0;
    weight = material.getDensity() * volume;
    return weight;


}
