//
// Created by matt on 08/11/18.
//

#include "Pyramid.h"

float Pyramid::calcVolume() const {
    std::vector<Vec3> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of pyramid from array of vertices
    Vec3 A = vertices[0] - vertices[1]; //VectA
    Vec3 B = vertices[0] - vertices[3]; //VectB
    Vec3 C = vertices[0] - vertices[4]; //VectC
    volume = std::abs((A*B).dot(C)) * (1.0/3.0);
    return volume;
}

Vec3 Pyramid::calcCentreofGravity() const {
    std::vector<Vec3> vertices = Cell::getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of pyramid from array of vertices
    Vec3 Sum = vertices[0]+ vertices[1]+ vertices[2]+vertices[3]+vertices[4];
    cog = Sum/5;
    return cog;
}

float Pyramid::calcWeight() const {
    const Material material = this->getCellMaterial();
    const float volume = this->getVolume();
    float weight = 0;
    weight = material.getDensity()*volume;
    return weight;
}
