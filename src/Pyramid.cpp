//
// Created by matt on 08/11/18.
//

#include "Pyramid.h"

Pyramid::Pyramid(const std::vector<Vec3> &CellVertices, Material CellMaterial)
: Cell(CellVertices, CellMaterial) {
    Pyramid::setVolume(Pyramid::calcVolume());
    Pyramid::setCentreOfGravity(Pyramid::calcCentreofGravity());
    Pyramid::setWeight(Pyramid::calcWeight());
}

float Pyramid::calcVolume() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of pyramid from array of vertices
    return volume;
}

Vec3 Pyramid::calcCentreofGravity() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of pyramid from array of vertices
    return cog;
}

float Pyramid::calcWeight() const {
    const Material material = Cell::getCellMaterial();
    const float volume = Cell::getVolume();
    float weight = 0;
    // TODO: Write function which will return weight of pyramid from volume and material
    return weight;
}
