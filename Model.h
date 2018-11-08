//
// Created by matt on 08/11/18.
//

#ifndef MODELLOADER_MODEL_H
#define MODELLOADER_MODEL_H

#include <vector>
#include <memory>

#include "Cell.h"

using namespace std;

class Model {
private:
    vector<std::unique_ptr<Cell>> Cells;
public:
    Model();

    const vector<unique_ptr<Cell>> &getCells() const;

    void setCells(const vector<unique_ptr<Cell>> &Cells);
};


#endif //MODELLOADER_MODEL_H
