//
// Created by matt on 08/11/18.
//

#pragma once

#include "Cell.h"

class Pyramid : public Cell {
public:
    Pyramid();

    explicit Pyramid(std::shared_ptr<Material> CellMaterial, int CellIndex);

    Pyramid(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial);
    ~Pyramid() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    double calcVolume() const override;
    Vec3 calcCentreofGravity() const override;
    double calcWeight() const override;
};
