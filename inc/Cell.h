//
// Created by matt on 08/11/18.
//

#pragma once

#include "Vec3.h"
#include "Material.h"
#include <vector>

class Cell {
private:
    std::vector<Vec3> CellVertices;
    Material CellMaterial;
    float Volume;
    Vec3 CentreOfGravity;
    float Weight;

public:
    explicit Cell(std::vector<Vec3> CellVertices, Material material);
    virtual ~Cell() = 0;

    const std::vector<Vec3> &getCellVertices() const;
    float getVolume() const;
    const Vec3 &getCentreOfGravity() const;
    float getWeight() const;
    const Material &getCellMaterial() const;

    void setCellVertices(const std::vector<Vec3> &CellVertices);
    void setVolume(float Volume);
    void setCentreOfGravity(const Vec3 &CentreOfGravity);
    void setWeight(float Weight);
    void setCellMaterial(const Material &CellMaterial);

    virtual float calcVolume() const = 0;
    virtual Vec3 calcCentreofGravity() const = 0;
    virtual float calcWeight() const = 0;
};
