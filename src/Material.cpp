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
    Material::Colour = Colour;
}

std::ostream &operator<<(std::ostream &os, const Material &mat) {
    os << mat.getName() << " has density " << mat.getDensity() << " and colour #" << mat.getColour() << '.';
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

