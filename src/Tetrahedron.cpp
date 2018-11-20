//
// Created by matt on 08/11/18.
//

#include "Tetrahedron.h"

float Tetrahedron::calcVolume() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of tetrahedron from array of vertices
    return volume;
}

Vec3 Tetrahedron::calcCentreofGravity() const {
    const std::vector<Vec3> vertices = Cell::getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of tetrahedron from array of vertices
    return cog;
}

float Tetrahedron::calcWeight() const {
    const Material material = Cell::getCellMaterial();
    const float volume = Cell::getVolume();
    float weight = 0;
    // TODO: Write function which will return weight of tetrahedron from volume and material
    return weight;
}
