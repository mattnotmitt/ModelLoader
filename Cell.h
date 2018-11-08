//
// Created by matt on 08/11/18.
//

#ifndef MODELLOADER_CELL_H
#define MODELLOADER_CELL_H

#include "Vector3D.h"
#include "Material.h"
#include <vector>
using namespace std;

class Cell {
private:
    vector<Vector3D> CellVertices;
    float Volume;
    Vector3D CentreOfGravity;
    float Weight;
    Material CellMaterial;

public:
    explicit Cell(vector<Vector3D> CellVertices, Material material);
    virtual ~Cell() = 0;

    const vector<Vector3D> &getCellVertices() const;
    float getVolume() const;
    const Vector3D &getCentreOfGravity() const;
    float getWeight() const;
    const Material &getCellMaterial() const;

    void setCellVertices(const vector<Vector3D> &CellVertices);
    void setVolume(float Volume);
    void setCentreOfGravity(const Vector3D &CentreOfGravity);
    void setWeight(float Weight);
    void setCellMaterial(const Material &CellMaterial);

    virtual float calcVolume() const = 0;
    virtual Vector3D calcCentreofGravity() const = 0;
    virtual float calcWeight() const = 0;
};


#endif //MODELLOADER_CELL_H
