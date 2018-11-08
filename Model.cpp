//
// Created by matt on 08/11/18.
//

#include "Model.h"

const vector<unique_ptr<Cell>> &Model::getCells() const {
    return Cells;
}

void Model::setCells(const vector<unique_ptr<Cell>> &Cells) {
    Model::Cells = Cells;
}

Model::Model() {}
