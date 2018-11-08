//
// Created by matt on 08/11/18.
//

#include "Model.h"

const std::vector<std::unique_ptr<Cell>> &Model::getCells() const {
    return Cells;
}

void Model::setCells(std::vector<std::unique_ptr<Cell>> &Cells) {
    Model::Cells = std::move(Cells);
}

Model::Model() = default;
