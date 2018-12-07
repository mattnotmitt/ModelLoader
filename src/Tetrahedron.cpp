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
    float volume;
    // TODO: Write function which will return volume of tetrahedron from array of vertices
    return volume;
}

Vec3 Tetrahedron::calcCentreofGravity() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of tetrahedron from array of vertices
    return cog;
}

double Tetrahedron::calcWeight() const {
    const Material material = *getCellMaterial();
    const double volume = getVolume();
    float weight = 0;
    // TODO: Write function which will return weight of tetrahedron from volume and material
    return weight;
}
