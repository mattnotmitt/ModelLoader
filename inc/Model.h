//
// Created by matt on 08/11/18.
//

#pragma once
/**
 * @file Model class definitions
 */
#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "Cell.h"
#include "Hexahedron.h"
#include "Material.h"
#include "Model.h"
#include "Pyramid.h"
#include "Tetrahedron.h"

/**
 * Model class holds all data about loaded Cell, Material and Vec3 instances \n
 * This should be passed to the software that requires the data from the file to be loaded
 */
class Model {
private:
    std::map<int, std::shared_ptr<Cell>> Cells;
    std::map<int, Material> Materials;
    std::map<int, Vec3> Vertices;
public:
    // Constructor & Destructor
    Model() = default;
    /**
     *
     * @param filePath
     */
    explicit Model(std::string &filePath);


    ~Model() = default;

    // Getters
    void setCells(std::map<int, std::shared_ptr<Cell>> &Cells);
    void setMaterials(const std::map<int, Material> &Materials);
    void setVertices(const std::map<int, Vec3> &Vertices);

    // Setters
    const std::map<int, std::shared_ptr<Cell>> &getCells() const;
    const std::map<int, Material> &getMaterials() const;
    const std::map<int, Vec3> &getVertices() const;

    // Main functions
    /**
     * Loads model from file path provided
     * @param filePath
     */
    void loadFile(std::string &filePath);
    /**
     * Saves model currently in Model class to specified path
     * @param filePath
     */
    void saveModel(std::string &filePath);
    /**
     * Calculates the centre of gravity of the entire Model class \n
     * Uses formula \f$\frac{\sum \hat{x}_i m_i}{m}\f$
     * @return
     */
    Vec3 calcCentreOfGravity();
    /**
     * Calculates the total weight of all Cell instances in the Model class
     * @return
     */
    double calcWeight();
    /**
     * Calculates the total volume of all Cell instances in the Model class
     * @return
     */
    double calcVolume();
    /**
     * Output stream of data about Model class
     * @param os
     * @param model
     * @return
     */
    friend std::ofstream &operator<<(std::ofstream &os, const Model &model);
};
