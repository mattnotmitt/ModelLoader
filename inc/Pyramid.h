//
// Created by matt on 08/11/18.
//

#pragma once

#include "Cell.h"

/**
 * @file Pyramid Class Definitions
 */

class Pyramid : public Cell {
public:
    Pyramid();

    explicit Pyramid(std::shared_ptr<Material> CellMaterial, int CellIndex);

    Pyramid(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial);
    ~Pyramid() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)

    /**
     * Calculates volume of pyramid
     * @return volume
     */
    double calcVolume() const override;

    /**
     * Calculates CoG of pyramid
     * @return Centre of Gravity
     */
    Vec3 calcCentreofGravity() const override;

    /**
     * Calculates Weight of pyramid
     * @return Weight
     */
    double calcWeight() const override;
};
