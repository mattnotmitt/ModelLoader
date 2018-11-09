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
    virtual ~Cell() = default;

    /**
     * Get vertices of Cell instance
     * @return vector of vertices of Cell
     */
    const std::vector<Vec3> &getCellVertices() const;
    /**
     * Get material of Cell instance
     * @return material of Cell instance
     */
    const Material& getCellMaterial() const;
    /**
     * Get volume of Cell instance
     * @return volume of Cell
     */
    float getVolume() const;
    /**
     * Get centre of gravity of Cell instance
     * @return Vec3 containing estimated centre of gravity location
     */
    const Vec3& getCentreOfGravity() const;
    /**
     * Get weight of Cell instance
     * @return weight of Cell instance
     */
    float getWeight() const;

    /**
     * Sets vertex coordinates of cell instance
     * @param CellVertices vector containing vertex coordinates
     */
    void setCellVertices(const std::vector<Vec3> &CellVertices);
    /**
     * Sets material of cell instance
     * @param CellMaterial
     */
    void setCellMaterial(const Material &CellMaterial);
    /**
     * Sets volume of cell instance
     * @param Volume
     */
    void setVolume(float Volume);
    /**
     * Set centre of gravity of cell instance
     * @param CentreOfGravity coordinates of centre of gravity
     */
    void setCentreOfGravity(const Vec3 &CentreOfGravity);
    /**
     * Set weight of cell instance
     * @param Weight
     */
    void setWeight(float Weight);

    /**
     * Calculate volume of cell instance
     * @return volume
     */
    virtual float calcVolume() const = 0;
    /**
     * Calculate centre of gravity of cell instance
     * @return centre of gravity
     */
    virtual Vec3 calcCentreofGravity() const = 0;
    /**
     * Calculate weight of cell instance
     * @return weight
     */
    virtual float calcWeight() const = 0;
};
