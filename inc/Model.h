//
// Created by matt on 08/11/18.
//

#pragma once

#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "Cell.h"
#include "Hexahedron.h"
#include "Material.h"
#include "Model.h"
#include "Pyramid.h"
#include "Tetrahedron.h"


class Model {
private:
    std::map<int, std::shared_ptr<Cell>> Cells;
    std::map<int, Material> Materials;
    std::map<int, Vec3> Vertices;
public:
    // Constructor & Destructor
    Model() = default;
    Model(std::string &filePath);


    ~Model() = default;

    // Getters
    void setCells(std::map<int, std::shared_ptr<Cell>> &Cells);
    void setMaterials(const std::map<int, Material> &Materials);
    void setVertices(const std::map<int, Vec3> &Vertices);

    // Setters
    const std::map<int, std::shared_ptr<Cell>> &getCells() const;
    const std::map<int, Material> &getMaterials() const;
    const std::map<int, Vec3> &getVertices() const;

    // Main functions
    void loadFile(std::string &filePath);
    void saveModel(std::string &filePath);

    friend std::ofstream &operator<<(std::ofstream &os, const Model &model);
};
