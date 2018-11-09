//
// Created by matt on 08/11/18.
//

#pragma once

#include "Cell.h"

class Tetrahedron : public Cell {
public:
    Tetrahedron(const std::vector<Vec3> &CellVertices, Material CellMaterial);
    ~Tetrahedron() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    float calcVolume() const override;
    Vec3 calcCentreofGravity() const override;
    float calcWeight() const override;
};