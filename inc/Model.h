//
// Created by matt on 08/11/18.
//

#pragma once

#include <map>
#include <memory>
#include <fstream>
#include <sstream>

#include "Cell.h"
#include "Model.h"

class Model {
private:
    std::map<int, std::unique_ptr<Cell>> Cells;
public:


private:
    std::map<int, Material> Materials;
public:
    // Constructor & Destructor
    Model();
    ~Model() = default;

    // Getters
    void setCells(const std::map<int, std::unique_ptr<Cell>> &Cells);
    void setMaterials(const std::map<int, Material> &Materials);

    // Setters
    const std::map<int, std::unique_ptr<Cell>> &getCells() const;
    const std::map<int, Material> &getMaterials() const;

    // Main functions
    void loadFile(std::string &filePath);
};
