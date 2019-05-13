//
// Created by matt on 08/11/18.
//

#pragma once

/**
 * @file Material Class definitions
 */

#include <regex>
#include <string>
#include <istream>
#include <fstream>
/**
 * Material class stores information about the material of each Cell
 */
class Material {
private:
    int Density;
    int index = -1;
    std::string Name;
    std::string Colour;
public:
    /**
     * Material default constructor
     */
    Material() : Density(0), Name(""), Colour("") {};
    /**
     * Material constructor with all data provided
     * @param Density
     * @param Name
     * @param Colour
     */
    Material(int Density, std::string &Name, std::string &Colour);
    /**
     * Materal class destructor
     */
    ~Material() = default;

    int getDensity() const;

    const std::string &getName() const;

    int getIndex() const;

    const std::string &getColour() const;

    void setDensity(int Density);

    void setName(const std::string &Name);

    void setIndex(int index);

    void setColour(const std::string &Colour);

    /**
     * Default output stream operator overload to output data about Material class
     * @param os
     * @param mat
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const Material &mat);
    /**
     * Output file stream operator overload to output data about Material class
     * @param os
     * @param mat
     * @return
     */
    friend std::ofstream &operator<<(std::ofstream &os, const Material &mat);

    /**
     * Input stream operator overload to read data about Material class from standard data format
     * @param is
     * @param mat
     * @return
     */
    friend std::istream &operator>>(std::istream &is, Material &mat);
};
