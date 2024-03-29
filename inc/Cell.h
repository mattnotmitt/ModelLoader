//
// Created by matt on 08/11/18.
//

#pragma once

/**
 * @file Cell class definitions
 */

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <map>
#include <string>

#include "Vec3.h"
#include "Material.h"

class Cell {
private:
    std::vector<std::shared_ptr<Vec3>> CellVertices;
    std::shared_ptr<Material> CellMaterial;
    float Volume = 0;
    Vec3 CentreOfGravity;
    float Weight = 0;
    int index = -1;

public:
    /**
     * Holds type of current Cell
     */
    enum class Type {
        NONE,
        TETRAHEDRON,
        PYRAMID,
        HEXAHEDRON
    };
    Type CellType = Type::NONE;

    Cell() = default;

    explicit Cell(std::shared_ptr<Material> material, int index);
    explicit Cell(std::vector<std::shared_ptr<Vec3>> CellVertices, std::shared_ptr<Material> material);
    virtual ~Cell() = default;

    /**
     * Overload generic output stream operator
     * @param os
     * @param cell
     * @return output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
    /**
     * Overload output filestream operator
     * @param os
     * @param cell
     * @return output fstream
     */
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
    double getVolume() const;
    /**
     * Get centre of gravity of Cell instance
     * @return Vec3 containing estimated centre of gravity location
     */
    const Vec3 getCentreOfGravity() const;
    /**
     * Get weight of Cell instance
     * @return weight of Cell instance
     */
    double getWeight() const;
    /**
     * Get index of cell instance
     * @return
     */
    int getIndex() const;

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
     * Sets index of cell instance
     * @param index
     */
    void setIndex(int index);


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
