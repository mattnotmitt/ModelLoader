//
// Created by matt on 08/11/18.
//

#include "Tetrahedron.h"

double Tetrahedron::calcVolume() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    double volume;
    // TODO: Write function which will return volume of tetrahedron from array of vertices
    volume = 1.0/6.0 * (((*vertices[2] * *vertices[1]) * (*vertices[2] * *vertices[0])).dot(*vertices[2] * *vertices[3]));      //formula for volume of tetrahedron
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
    weight = material.getDensity() * volume;
    return weight;


}
