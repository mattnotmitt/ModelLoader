//
// Created by matt on 08/11/18.
//

#pragma once

#include <regex>
#include <string>
#include <istream>

class Material {
private:
    int Density;
    int index = -1;
    std::string Name;
    std::string Colour;
public:
    Material() : Density(0), Name(""), Colour("") {};

    Material(int Density, std::string &Name, std::string &Colour);

    ~Material() = default;

    int getDensity() const;

    const std::string &getName() const;

    int getIndex() const;

    const std::string &getColour() const;

    void setDensity(int Density);

    void setName(const std::string &Name);

    void setIndex(int index);

    void setColour(const std::string &Colour);

    friend std::ostream &operator<<(std::ostream &os, const Material &mat);
    friend std::ofstream &operator<<(std::ofstream &os, const Material &mat);

    friend std::istream &operator>>(std::istream &is, Material &mat);
};
