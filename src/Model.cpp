//
// Created by matt on 08/11/18.
//

#include "Model.h"

void Model::loadFile(std::string &filePath) {
    std::map<int, std::unique_ptr<Cell>> Cells;
    std::map<int, Vec3> Vertices;
    std::map<int, Material> Materials;

    std::ifstream infile(filePath);
    if (!infile.is_open()) {

    }
    std::string line;
    int lineNum = 0;
    try {
        while (std::getline(infile, line)) {
            if (line == "\r") continue;
            lineNum++;
            std::istringstream iss(line);
            if (iss.str().empty()) continue;
            char type;
            int index;

            iss >> type >> index;
            switch (type) {
                case 'm': { // Parse material declaratiion line
                    Material mat;
                    iss >> mat;

                    std::cout << "Material " << index << ": " << mat << std::endl;
                    Materials.try_emplace(index, mat);
                    break;
                }
                case 'v': { // Parse vertex declaration line
                    Vec3 vec;
                    iss >> vec;
                    std::cout << "Vertex " << index << ": " << vec << std::endl;
                    Vertices.try_emplace(index, vec);
                    break;
                }
                case 'c': { // Parse cell declaration line
                    std::unique_ptr<Cell> cell;
                    char cellType;
                    int materialIndex, vertexIndex, vertexCount;
                    std::vector<Vec3> vertices;

                    iss >> cellType >> materialIndex;

                    switch (cellType) {
                        case 'h': {
                            cell = std::make_unique<Hexahedron>(Materials.at(materialIndex));
                            vertexCount = 8;
                            break;
                        }
                        case 'p': {
                            cell = std::make_unique<Pyramid>(Materials.at(materialIndex));
                            vertexCount = 5;
                            break;
                        }
                        case 't': {
                            cell = std::make_unique<Tetrahedron>(Materials.at(materialIndex));
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
                            vertices.push_back(Vertices.at(vertexIndex));
                        }
                    }

                    if (vertices.size() != vertexCount) {
                        throw "Number of vertices too large for specified cell type.";
                    }

                    cell->setCellVertices(vertices);
                    std::cout << "Cell " << index << ": " << *cell.get() << std::endl;
                    Cells.try_emplace(index, std::move(cell));
                    break;
                }
                case '#':
                    //std::cout << "Comment" << std::endl;
                    break;
                default:
                    throw "Unknown character.";
            }
        }
        this->setCells(Cells);
        this->setMaterials(Materials);
    } catch (std::string &msg) {
        std::cerr << "Error on line " << lineNum << " in " << filePath << ": " << msg << std::endl;
    }
}

const std::map<int, Material> &Model::getMaterials() const {
    return Materials;
}

void Model::setMaterials(const std::map<int, Material> &Materials) {
    Model::Materials = Materials;
}

void Model::setCells(std::map<int, std::unique_ptr<Cell>> &Cells) {
    Model::Cells = std::move(Cells);
}

const std::map<int, std::unique_ptr<Cell>> &Model::getCells() const {
    return Cells;
}

SCENARIO("Can correctly load a model file", "[Model]") {
    GIVEN("A file path of a small model file") {
        std::string filePath = "../test/ExampleModel1.mod";
        WHEN("The file is parsed") {
            Model ExampleModel1;
            ExampleModel1.loadFile(filePath);
            REQUIRE(ExampleModel1.getMaterials().size() == 2);
            REQUIRE(ExampleModel1.getCells().at(0)->getCellMaterial().getName() == "copper");
        }
    }
    GIVEN("A file path of a large model file") {
        std::string filePath = "../test/ExampleModel2.mod";
        WHEN("The file is parsed") {
            Model ExampleModel2;
            ExampleModel2.loadFile(filePath);
            REQUIRE(ExampleModel2.getMaterials().size() == 2);
            REQUIRE(ExampleModel2.getCells().at(0)->getCellMaterial().getName() == "cu");
        }
    }
}
