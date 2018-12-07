#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
//
// Created by matt on 08/11/18.
//

#include "Hexahedron.h"

Hexahedron::Hexahedron(std::shared_ptr<Material> CellMaterial, int CellIndex) : Cell(CellMaterial, CellIndex) {
    this->CellType = Cell::Type::HEXAHEDRON;
}

Hexahedron::Hexahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial)
        : Cell::Cell(CellVertices, CellMaterial) {
    this->CellType = Cell::Type::HEXAHEDRON;
}

double Hexahedron::calcVolume() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    double volume, volume1, volume2, volume3 = 0;
    Vec3 A = *vertices[0] - *vertices[1]; //VectA
    Vec3 B = *vertices[0] - *vertices[3]; //VectB
    Vec3 C = *vertices[0] - *vertices[4]; //VectC
    volume1 = std::abs((A*B).dot(C)) * (1.0/3.0);
    Vec3 D = *vertices[3] - *vertices[0]; //VectD
    Vec3 E = *vertices[3] - *vertices[7]; //VectE
    Vec3 F = *vertices[3] - *vertices[2]; //VectF
    volume2 = std::abs((D*E).dot(F)) * (1.0/3.0);
    Vec3 I = *vertices[1] - *vertices[5]; //VectI
    Vec3 J = *vertices[1] - *vertices[2]; //VectJ
    Vec3 K = *vertices[1] - *vertices[0]; //VectK
    volume3 = std::abs((I*J).dot(K)) * (1.0/3.0);
    volume = volume1+volume2+volume3;
    return volume;
};

Vec3 Hexahedron::calcCentreofGravity() const {
    const std::vector<std::shared_ptr<Vec3>> vertices = getCellVertices();
    Vec3 cog;
    Vec3 Sum = *vertices[0]+ *vertices[1]+ *vertices[2] + *vertices[3] + *vertices[4] + *vertices[5] + *vertices[6] + *vertices[7];
    cog = Sum/8;
    return cog;
}

double Hexahedron::calcWeight() const {
    const Material material = *getCellMaterial();
    const double volume = getVolume();
    double weight = 0;
    weight = material.getDensity() * volume;
    return weight;
}

#pragma clang diagnostic pop