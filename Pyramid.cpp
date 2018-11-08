//
// Created by matt on 08/11/18.
//

#include "Pyramid.h"

Pyramid::Pyramid(const vector<Vector3D> &CellVertices, Material CellMaterial)
: Cell(CellVertices, CellMaterial) {
    Pyramid::setVolume(Pyramid::calcVolume());
    Pyramid::setCentreOfGravity(Pyramid::calcCentreofGravity());
    Pyramid::setWeight(Pyramid::calcWeight());
}

Pyramid::~Pyramid() = default;

float Pyramid::calcVolume() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    float volume;
    // TODO: Write function which will return volume of pyramid from array of vertices
    return volume;
}

Vector3D Pyramid::calcCentreofGravity() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    Vector3D cog;
    // TODO: Write function which will return centre of gravity of pyramid from array of vertices
    return cog;
}

float Pyramid::calcWeight() const {
    const vector<Vector3D> vertices = Cell::getCellVertices();
    const Material material = Cell::getCellMaterial();
    float weight;
    // TODO: Write function which will return weight of pyramid from array of vertices
    return weight;
}
