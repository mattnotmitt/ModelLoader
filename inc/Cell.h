//
// Created by matt on 08/11/18.
//

#pragma once

#include <memory>
#include <vector>

#include "Vec3.h"
#include "Material.h"

class Cell {
private:
    std::vector<std::shared_ptr<Vec3>> CellVertices;
    std::shared_ptr<Material> CellMaterial;
    float Volume = 0;
    Vec3 CentreOfGravity;
    float Weight = 0;

public:
    enum class Type {
        NONE,
        TETRAHEDRON,
        PYRAMID,
        HEXAHEDRON
    };
    Type CellType = Type::NONE;

    Cell() = default;

    explicit Cell(std::shared_ptr<Material> material) : CellMaterial(material) {};
    explicit Cell(std::vector<std::shared_ptr<Vec3>> CellVertices, std::shared_ptr<Material> material);
    virtual ~Cell() = default;

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
    friend std::ofstream &operator<<(std::ofstream &os, const Cell &cell);

    /**
     * Get vertices of Cell instance
     * @return vector of vertices of Cell
     */
    const std::vector<std::shared_ptr<Vec3>>& getCellVertices() const;
    /**
     * Get material of Cell instance
     * @return material of Cell instance
     */
    const std::shared_ptr<Material>& getCellMaterial() const;
    /**
     * Get volume of Cell instance
     * @return volume of Cell
     */
    float getVolume() const;
    /**
     * Get centre of gravity of Cell instance
     * @return Vec3 containing estimated centre of gravity location
     */
    const Vec3 getCentreOfGravity() const;
    /**
     * Get weight of Cell instance
     * @return weight of Cell instance
     */
    float getWeight() const;

    /**
     * Sets vertex coordinates of cell instance
     * @param CellVertices vector containing vertex coordinates
     */
    void setCellVertices(const std::vector<std::shared_ptr<Vec3>> &CellVertices);
    /**
     * Sets material of cell instance
     * @param CellMaterial
     */
    void setCellMaterial(const std::shared_ptr<Material> &CellMaterial);

    /**
     * Calculate volume of cell instance
     * @return volume
     */
    virtual double calcVolume() const = 0;
    /**
     * Calculate centre of gravity of cell instance
     * @return centre of gravity
     */
    virtual Vec3 calcCentreofGravity() const = 0;
    /**
     * Calculate weight of cell instance
     * @return weight
     */
    virtual double calcWeight() const = 0;
};
