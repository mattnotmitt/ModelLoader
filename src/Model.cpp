//
// Created by matt on 08/11/18.
//

#include "Model.h"

Model::Model(std::string &filePath) {
  this->loadFile(filePath);
};

void Model::loadFile(std::string &filePath) {
    std::ifstream infile(filePath); // Open input file
    if (!infile.is_open()) {
        throw std::runtime_error("Could not open input file.");
    }
    std::string line;
    int lineNum = 0;
    try {
        while (std::getline(infile, line)) { // Get line from file and store in line variable
            if (line == "\r" || line == "\n") continue; // Skip line if only contains newline
            lineNum++;
            std::istringstream iss(line);
            if (iss.str().empty()) continue; // Skip line if stream is empty
            char type;
            int index;

            iss >> type >> index; // read in type and index values
            switch (type) {
                case 'm': { // Parse material declaration line
                    if (Materials.count(index) != 0) // Check if material already declared
                        throw std::string("Material " + std::to_string(index) + " already declared.");
                    Material mat; // Create instance of material
                    mat.setIndex(index); // Set index of material for outputting
                    iss >> mat; // Read data into mat class

                    std::cout << "DEBUG | " << mat << std::endl; // Print info about material
                    Materials.emplace(index, mat); // Store in Model's map of materials
                    break;
                }
                case 'v': { // Parse vertex declaration line
                    if (Vertices.count(index) != 0) // Check if vertex already declared
                        throw std::string("Vertex " + std::to_string(index) + " already declared.");
                    Vec3 vec;
                    vec.setIndex(index);
                    iss >> vec; // Read data into vector class
                    std::cout << "TRACE | Vertex " << index << ": " << vec << std::endl;
                    Vertices.emplace(index, vec); // Store in model's map of vertices
                    break;
                }
                case 'c': { // Parse cell declaration line
                    if (Cells.count(index) != 0) // Check if cell is already declared
                        throw std::string("Cell " + std::to_string(index) + " already declared.");
                    std::shared_ptr<Cell> cell;
                    char cellType;
                    int materialIndex, vertexIndex, vertexCount;
                    std::vector<std::shared_ptr<Vec3>> cellVertices;

                    iss >> cellType >> materialIndex;

                    switch (cellType) { // Select cell type
                        case 'h': {
                            // Create shared pointer to hexahedron cell type with pointer to material and the cell's index
                            cell = std::make_shared<Hexahedron>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 8;
                            break;
                        }
                        case 'p': {
                            // Create shared pointer to pyramid cell type with pointer to material and the cell's index
                            cell = std::make_shared<Pyramid>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 5;
                            break;
                        }
                        case 't': {
                            // Create shared pointer to tetrahedron cell type with pointer to material and the cell's index
                            cell = std::make_shared<Tetrahedron>(std::make_shared<Material>(Materials.at(materialIndex)), index);
                            vertexCount = 4;
                            break;
                        }
                        default: // Rejects if cell not recognised
                            throw std::string("Invalid cell type " + std::to_string(cellType) + " specified.");
                    }

                    while (iss >> vertexIndex) { // Load in vertex indexes
                        if (Vertices.count(vertexIndex) == 0) { // Make sure vertex exists
                            throw std::string("Vertex " + std::to_string(vertexIndex) + " not found.");
                        } else { // Adds vertex to list of cell vertices
                            cellVertices.push_back(std::make_shared<Vec3>(Vertices.at(vertexIndex)));
                        }
                    }

                    if (cellVertices.size() != vertexCount) { // Checks if too many vertices have been loaded for cell type
                        throw std::string("Number of vertices too large for specified cell type.");
                    }

                    cell->setCellVertices(cellVertices); // Store list of cell vertices
                    std::cout << "DEBUG | " << *cell << std::endl; // Output details about cell
                    Cells.emplace(index, std::move(cell)); // Store cell in Model map of cells
                    break;
                }
                case '#':
                    //std::cout << "Comment" << std::endl;
                    break;
                default:
                    throw std::string("Unknown character.");
            }
        }
    } catch (std::string &msg) {
        // Throw error with information about where issue is in file
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

void Model::saveModel(std::string &filePath) {
    std::ofstream outfile;
    outfile.open(filePath);
    if (!outfile.is_open()) {
        throw std::runtime_error("Could not open output file.");
    }
    outfile << *this << std::endl; // Use overloaded output operator
    outfile.close();
}

std::ofstream &operator<<(std::ofstream &os, const Model &model) {
    std::map<int, Material> materials = model.getMaterials();
    std::map<int, Vec3> vertices = model.getVertices();
    std::map<int, std::shared_ptr<Cell>> cells = model.getCells();

    for (const auto& material: materials){ // Loop through materials and save information about them to file
        os << material.second << std::endl;
    }
    os << std::endl;
    for (const auto& vertex: vertices){ // Loop through vertices and save information about them to file
        os << vertex.second << std::endl;
    }
    os << std::endl;
    for (const auto& cell: cells){ // Loop through cells and save information about them to file
        os << *cell.second << std::endl;
    }

    return os;
}

Vec3 Model::calcCentreOfGravity() {
    Vec3 weightedTotal;
    for (const auto& cellPair: getCells()) {
        auto cell = cellPair.second;
        auto weightedCOG = cell->getCentreOfGravity() * cell->getWeight();
        weightedTotal = weightedTotal + weightedCOG;
    }
    return weightedTotal / calcWeight();
}

double Model::calcWeight() {
    double weight = 0;
    for (const auto& cellPair: getCells()) {
        auto cell = cellPair.second;
        weight += cell->getWeight();
    }
    return weight;
}

double Model::calcVolume() {
    double volume = 0;
    for (const auto& cellPair: getCells()) {
        auto cell = cellPair.second;
        volume += cell->getVolume();
    }
    return volume;
}
