//
// Created by matt on 08/11/18.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(const vector<Vector3D> &CellVertices, Material CellMaterial)
: Cell(CellVertices, CellMaterial) {
    Cell::setVolume(Tetrahedron::calcVolume());
    Cell::setCentreOfGravity(Tetrahedron::calcCentreofGravity());
    Cell::setWeight(Tetrahedron::calcWeight());
}

Tetrahedron::~Tetrahedron() = default;

float Tetrahedron::calcVolume() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of tetrahedron from array of vertices
    return volume;
}

Vector3D Tetrahedron::calcCentreofGravity() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    Vector3D cog;
    // TODO: Write function which will return centre of gravity of tetrahedron from array of vertices
    return cog;
}

float Tetrahedron::calcWeight() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    const Material material = Cell::getCellMaterial();
    float weight;
    // TODO: Write function which will return weight of tetrahedron from array of vertices
    return weight;
}
