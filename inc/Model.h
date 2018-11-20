//
// Created by matt on 08/11/18.
//

#pragma once

#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>

#include "catch.hpp"

#include "Cell.h"
#include "Hexahedron.h"
#include "Material.h"
#include "Model.h"
#include "Pyramid.h"
#include "Tetrahedron.h"


class Model {
private:
    std::map<int, std::unique_ptr<Cell>> Cells;
    std::map<int, Material> Materials;
public:
    // Constructor & Destructor
    Model() = default;

    Model(std::map<int, std::unique_ptr<Cell>> &Cells, std::map<int, Material> &Materials)
            : Cells(std::move(Cells)), Materials(std::move(Materials)) {};

    ~Model() = default;

    // Getters
    void setCells(std::map<int, std::unique_ptr<Cell>> &Cells);
    void setMaterials(const std::map<int, Material> &Materials);

    // Setters
    const std::map<int, std::unique_ptr<Cell>> &getCells() const;
    const std::map<int, Material> &getMaterials() const;

    // Main functions
    void loadFile(std::string &filePath);
};
