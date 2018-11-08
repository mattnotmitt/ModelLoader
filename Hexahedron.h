//
// Created by matt on 08/11/18.
//

#ifndef MODELLOADER_HEXAHEDRON_H
#define MODELLOADER_HEXAHEDRON_H

#include "Cell.h"

class Hexahedron : public Cell {
public:
    Hexahedron(const vector<Vector3D> &CellVertices, Material CellMaterial);
    ~Hexahedron() override;

    float calcVolume() const override;
    Vector3D calcCentreofGravity() const override;
    float calcWeight() const override;
};


#endif //MODELLOADER_HEXAHEDRON_H
