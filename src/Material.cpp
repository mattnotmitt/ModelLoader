//
// Created by matt on 08/11/18.
//

#include "Material.h"

Material::Material(int Density, std::string &Name, std::string &Colour)
        : Density(Density), Name(std::move(Name)), Colour(std::move(Colour)) {};

int Material::getDensity() const {
    return Density;
}

void Material::setDensity(int Density) {
    Material::Density = Density;
}

const std::string &Material::getName() const {
    return Name;
}

void Material::setName(const std::string &Name) {
    Material::Name = Name;
}

const std::string &Material::getColour() const {
    return Colour;
}

void Material::setColour(const std::string &Colour) {
    std::regex colourRegex("^(?:[0-9a-fA-F]{3}){1,2}$");
    if (!(std::regex_match(Colour, colourRegex))) throw "Invalid colour string " + Colour + " for material.";
    Material::Colour = Colour;
}

std::ostream &operator<<(std::ostream &os, const Material &mat) {
    os << mat.getName() << " (" << mat.getIndex() << ") has density " << mat.getDensity() << " and colour #" << mat.getColour() << '.';
    return os;
}

std::ofstream &operator<<(std::ofstream &os, const Material &mat) {
    os  << "m " << mat.getIndex() << " " << mat.getDensity() << " " << mat.getColour() << " " << mat.getName();
    return os;
}

std::istream &operator>>(std::istream &is, Material &mat) {
    int density;
    std::string name, colour;

    is >> density >> colour >> name;

    mat.setDensity(density);
    mat.setColour(colour);
    mat.setName(name);
    return is;
}

int Material::getIndex() const {
    return index;
}

void Material::setIndex(int index) {
    Material::index = index;
}

