//
// Created by matt on 08/11/18.
//

#pragma once

#include "Cell.h"

class Pyramid : public Cell {
public:
    Pyramid() = default;

    Pyramid(const Material &CellMaterial) : Cell(CellMaterial) {};

    Pyramid(const std::vector<Vec3> &CellVertices, const Material &CellMaterial)
            : Cell(CellVertices, CellMaterial) {};
    ~Pyramid() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    float calcVolume() const override;
    Vec3 calcCentreofGravity() const override;
    float calcWeight() const override;
};
