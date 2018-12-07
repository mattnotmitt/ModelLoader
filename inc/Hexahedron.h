//
// Created by matt on 08/11/18.
//

#pragma once

#include <cmath>
#include "Cell.h"

class Hexahedron : public Cell {
public:
    Hexahedron() {
        this->CellType = Cell::Type::HEXAHEDRON;
    };

    Hexahedron(std::shared_ptr<Material> CellMaterial) : Cell(CellMaterial) {
        this->CellType = Cell::Type::HEXAHEDRON;
    };

    Hexahedron(std::vector<std::shared_ptr<Vec3>> &CellVertices, std::shared_ptr<Material> CellMaterial)
            : Cell::Cell(CellVertices, CellMaterial) {
        this->CellType = Cell::Type::HEXAHEDRON;
    }
    ~Hexahedron() override = default;

    // const keyword disallows modification of class by function
    // override keyword marks as overwriting virtual keyword from base class (Cell)
    double calcVolume() const override;
    Vec3 calcCentreofGravity() const override;
    double calcWeight() const override;
};
