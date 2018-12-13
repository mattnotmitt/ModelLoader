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

/**
 * Find volume of tetrahedron
 * @return
 */
double Tetrahedron::calcVolume() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    double volume;
    Vec3 A = *vertices[0] - *vertices[1]; //VectA
    Vec3 B = *vertices[0] - *vertices[2]; //VectB
    Vec3 C = *vertices[0] - *vertices[3]; //VectC
    volume = std::abs((A*B).dot(C)) * (1.0/6.0);
    return volume;
}

/**
 * Sum all vertices and divide by 4 to find centre of gravity
 * @return
 */
Vec3 Tetrahedron::calcCentreofGravity() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    Vec3 cog;
    cog = (*vertices[0]+*vertices[1]+*vertices[2]+*vertices[3])/4.0;
    return cog;
}

/**
 * Multiply volume and density of material to find weight of Cell
 * @return
 */
double Tetrahedron::calcWeight() const {
    const Material material = *getCellMaterial();
    const double volume = getVolume();
    double weight = 0;
    weight = material.getDensity() * volume;
    return weight;
}
