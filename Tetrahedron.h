//
// Created by matt on 08/11/18.
//

#ifndef MODELLOADER_TETRAHEDRON_H
#define MODELLOADER_TETRAHEDRON_H

#include "Cell.h"

class Tetrahedron : public Cell {
    Tetrahedron(const vector<Vector3D> &CellVertices, Material CellMaterial);
    ~Tetrahedron() override;

    float calcVolume() const override;
    Vector3D calcCentreofGravity() const override;
    float calcWeight() const override;
};


#endif //MODELLOADER_TETRAHEDRON_H
