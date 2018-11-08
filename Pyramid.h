//
// Created by matt on 08/11/18.
//

#ifndef MODELLOADER_PYRAMID_H
#define MODELLOADER_PYRAMID_H

#include "Cell.h"

class Pyramid : public Cell {
    Pyramid(const vector<Vector3D> &CellVertices, Material CellMaterial);
    ~Pyramid() override;
    float calcVolume() const override;
    Vector3D calcCentreofGravity() const override;
    float calcWeight() const override;
};


#endif //MODELLOADER_PYRAMID_H
