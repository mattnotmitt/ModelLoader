//
// Created by matt on 08/11/18.
//

#include "Hexahedron.h"

float Hexahedron::calcVolume() const {
    std::vector<Vec3> vertices = Cell::getCellVertices();
    float volume = 0;
    float volume1 = 0;
    float volume2 = 0;
    float volume3 = 0;
    // TODO: Write function which will return volume of hexahedron from array of vertices
    Vec3 A = vertices[0] - vertices[1]; //VectA
    Vec3 B = vertices[0] - vertices[3]; //VectB
    Vec3 C = vertices[0] - vertices[4]; //VectC
    volume1 = std::abs((A*B).dot(C)) * (1.0/3.0);
    Vec3 D = vertices[3] - vertices[0]; //VectD
    Vec3 E = vertices[3] - vertices[7]; //VectE
    Vec3 F = vertices[3] - vertices[2]; //VectF
    volume2 = std::abs((D*E).dot(F)) * (1.0/3.0);
    Vec3 I = vertices[1] - vertices[5]; //VectI
    Vec3 J = vertices[1] - vertices[2]; //VectJ
    Vec3 K = vertices[1] - vertices[0]; //VectK
    volume3 = std::abs((I*J).dot(K)) * (1.0/3.0);
    volume = volume1+volume2+volume3;
    return volume;
};

Vec3 Hexahedron::calcCentreofGravity() const {
    std::vector<Vec3> vertices = Cell::getCellVertices();
    Vec3 cog;
    // TODO: Write function which will return centre of gravity of hexahedron from array of vertices
    Vec3 Sum = vertices[0]+ vertices[1]+ vertices[2]+vertices[3]+vertices[4]+vertices[5]+vertices[6]+vertices[7];
    cog = Sum/8;
    return cog;
}

float Hexahedron::calcWeight() const {
    const Material material = this->getCellMaterial();
    const float volume = this->getVolume();
    float weight = 0;
    // TODO: Write function which will return weight of hexahedron from volume and material
    weight = material.getDensity()*volume;
    return weight;
}
