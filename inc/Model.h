//
// Created by matt on 08/11/18.
//

#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Model {
private:
    std::vector<std::unique_ptr<Cell>> Cells;
public:
    Model();

    const std::vector<std::unique_ptr<Cell>>& getCells() const;

    void setCells(std::vector<std::unique_ptr<Cell>> &Cells);
};
