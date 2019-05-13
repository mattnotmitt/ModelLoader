//
// Created by matt on 08/11/18.
//

#pragma once

/**
 * @file Hexahedron Class Definitions
 */

#include <cmath>
#include "Cell.h"

class Hexahedron : public Cell {
public:
    Hexahedron() {
        this->CellType = Cell::Type::HEXAHEDRON;
    };

    Hexahedron(std::shared_ptr<Material> CellMaterial, int CellIndex);

    Hexahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial);
    ~Hexahedron() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    /**
     * Calculates volume of hexahedron
     * @return volume
     */
    double calcVolume() const override;

    /**
     * Calculates CoG of hexahedron
     * @return Centre of Gravity
     */
    Vec3 calcCentreofGravity() const override;

    /**
     * Calculates Weight of hexahedron
     * @return Weight
     */
    double calcWeight() const override;
};
