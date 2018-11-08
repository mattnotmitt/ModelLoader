//
// Created by matt on 08/11/18.
//

#include "Hexahedron.h"

Hexahedron::Hexahedron(const vector<Vector3D> &CellVertices, Material CellMaterial)
: Cell(CellVertices, CellMaterial) {
    Cell::setVolume(Hexahedron::calcVolume());
    Cell::setCentreOfGravity(Hexahedron::calcCentreofGravity());
    Cell::setWeight(Hexahedron::calcWeight());
}

Hexahedron::~Hexahedron() = default;

float Hexahedron::calcVolume() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of hexahedron from array of vertices
    return volume;
};

Vector3D Hexahedron::calcCentreofGravity() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    Vector3D cog;
    // TODO: Write function which will return centre of gravity of hexahedron from array of vertices
    return cog;
}

float Hexahedron::calcWeight() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    const Material material = Cell::getCellMaterial();
    float weight;
    // TODO: Write function which will return weight of hexahedron from array of vertices
    return weight;
}
