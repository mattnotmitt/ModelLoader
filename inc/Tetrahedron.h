//
// Created by matt on 08/11/18.
//

#pragma once

#include <numeric>
#include <algorithm>
#include "Cell.h"


/**
 * @file Tetrahedron Class Definitions
 */

class Tetrahedron : public Cell {
public:
    Tetrahedron();

    Tetrahedron(std::shared_ptr<Material> CellMaterial, int CellIndex);

    Tetrahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial);
    ~Tetrahedron() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)

    /**
     * Calculates volume of tetrahedron
     * @return volume
     */
    double calcVolume() const override;

    /**
     * Calculates CoG of tetrahedron
     * @return Centre of Gravity
     */
    Vec3 calcCentreofGravity() const override;

    /**
     * Calculates Weight of tetrahedron
     * @return Weight
     */
    double calcWeight() const override;
};
