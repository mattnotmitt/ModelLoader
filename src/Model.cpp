//
// Created by matt on 08/11/18.
//

#include "Model.h"

void Model::loadFile(std::string &filePath) {
    std::ifstream infile(filePath);
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        // TODO: Line processing logic
    }
}

const std::map<int, Material> &Model::getMaterials() const {
    return Materials;
}

void Model::setMaterials(const std::map<int, Material> &Materials) {
    Model::Materials = Materials;
}

void Model::setCells(const std::map<int, std::unique_ptr<Cell>> &Cells) {
    Model::Cells = Cells;
}

const std::map<int, std::unique_ptr<Cell>> &Model::getCells() const {
    return Cells;
}

Model::Model() = default;
