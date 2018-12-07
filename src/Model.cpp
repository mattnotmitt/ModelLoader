//
// Created by matt on 08/11/18.
//

#include <Model.h>

#include "Model.h"

Model::Model(std::string &filePath) {
  this->loadFile(filePath);
};

void Model::loadFile(std::string &filePath) {
    std::ifstream infile(filePath);
    if (!infile.is_open()) {

    }
    std::string line;
    int lineNum = 0;
    try {
        while (std::getline(infile, line)) {
            if (line == "\r" || line == "\n") continue;
            lineNum++;
            std::istringstream iss(line);
            if (iss.str().empty()) continue;
            char type;
            int index;

            iss >> type >> index;
            switch (type) {
                case 'm': { // Parse material declaration line
                    if (Materials.count(index) != 0) throw "Material " + std::to_string(index) + " already declared.";
                    Material mat;
                    mat.setIndex(index);
                    iss >> mat;

                    std::cout << mat << std::endl;
                    Materials.emplace(index, mat);
                    break;
                }
                case 'v': { // Parse vertex declaration line
                    if (Vertices.count(index) != 0) throw "Vertex " + std::to_string(index) + " already declared.";
                    Vec3 vec;
                    vec.setIndex(index);
                    iss >> vec;
                    //std::cout << "Vertex " << index << ": " << vec << std::endl;
                    Vertices.emplace(index, vec);
                    break;
                }
                case 'c': { // Parse cell declaration line
                    if (Cells.count(index) != 0) throw "Cell " + std::to_string(index) + " already declared.";
                    std::shared_ptr<Cell> cell;
                    char cellType;
                    int materialIndex, vertexIndex, vertexCount;
                    std::vector<std::shared_ptr<Vec3>> cellVertices;

                    iss >> cellType >> materialIndex;

                    switch (cellType) {
                        case 'h': {
                            cell = std::make_shared<Hexahedron>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 8;
                            break;
                        }
                        case 'p': {
                            cell = std::make_shared<Pyramid>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 5;
                            break;
                        }
                        case 't': {
                            cell = std::make_shared<Tetrahedron>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 4;
                            break;
                        }
                        default:
                            throw "Invalid cell type " + std::to_string(cellType) + " specified.";
                    }

                    while (iss >> vertexIndex) {
                        if (Vertices.count(vertexIndex) == 0) {
                            throw "Vertex " + std::to_string(vertexIndex) + " not found.";
                        } else {
                            cellVertices.push_back(std::make_shared<Vec3>(Vertices.at(vertexIndex)));
                        }
                    }

                    if (cellVertices.size() != vertexCount) {
                        throw "Number of vertices too large for specified cell type.";
                    }

                    cell->setCellVertices(cellVertices);
                    std::cout << *cell << std::endl;
                    Cells.emplace(index, std::move(cell));
                    break;
                }
                case '#':
                    //std::cout << "Comment" << std::endl;
                    break;
                default:
                    throw "Unknown character.";
            }
        }
    } catch (std::string &msg) {
        throw std::runtime_error("Error on line " + std::to_string(lineNum) + " in " + filePath + ": " + msg);
    }
}

const std::map<int, Material> &Model::getMaterials() const {
    return Materials;
}

const std::map<int, std::shared_ptr<Cell>> &Model::getCells() const {
    return Cells;
}

const std::map<int, Vec3> &Model::getVertices() const {
    return Vertices;
}

void Model::setMaterials(const std::map<int, Material> &Materials) {
    Model::Materials = Materials;
}

void Model::setCells(std::map<int, std::shared_ptr<Cell>> &Cells) {
    Model::Cells = std::move(Cells);
}

void Model::setVertices(const std::map<int, Vec3> &Vertices) {
    Model::Vertices = Vertices;
}

std::ofstream &operator<<(std::ofstream &os, const Model &model) {
    //TODO: when this is called output the file as it looks in the input
    std::map<int, Material> materials = model.getMaterials();
    std::map<int, Vec3> vertices = model.getVertices();
    std::map<int, std::shared_ptr<Cell>> cells = model.getCells();

    for (const auto& material: materials){
        os << material.second << std::endl;
    }
    for (const auto& vertex: vertices){
        os << vertex.second << std::endl;
    }
    for (const auto& cell: cells){
        os << *cell.second << std::endl;
    }

    return os;
}
