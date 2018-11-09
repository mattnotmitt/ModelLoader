//
// Created by matt on 08/11/18.
//

#include "Hexahedron.h"

Hexahedron::Hexahedron(const std::vector<Vec3> &CellVertices, Material CellMaterial)
: Cell::Cell(CellVertices, CellMaterial) {
    Cell::setVolume(Hexahedron::calcVolume());
    Cell::setCentreOfGravity(Hexahedron::calcCentreofGravity());
    Cell::setWeight(Hexahedron::calcWeight());
}

float Hexahedron::calcVolume() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    float volume = 0;
    // TODO: Write function which will return volume of hexahedron from array of vertices
    return volume;
};

Vec3 Hexahedron::calcCentreofGravity() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of hexahedron from array of vertices
    return cog;
}

float Hexahedron::calcWeight() const {
    const Material material = Cell::getCellMaterial();
    const float volume = Cell::getVolume();
    float weight = 0;
    // TODO: Write function which will return weight of hexahedron from volume and material
    return weight;
}
