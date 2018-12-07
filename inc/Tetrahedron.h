//
// Created by matt on 08/11/18.
//

#pragma once

#include <numeric>
#include <algorithm>
#include "Cell.h"

class Tetrahedron : public Cell {
public:
    Tetrahedron() {
        this->CellType = Cell::Type::TETRAHEDRON;
    };

    Tetrahedron(std::shared_ptr<Material> CellMaterial, int CellIndex) : Cell(CellMaterial, CellIndex) {
        this->CellType = Cell::Type::TETRAHEDRON;
    };

    Tetrahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial)
            : Cell(CellVertices, CellMaterial) {
        this->CellType = Cell::Type::TETRAHEDRON;
    };
    ~Tetrahedron() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    double calcVolume() const override;
    Vec3 calcCentreofGravity() const override;
    double calcWeight() const override;
};
