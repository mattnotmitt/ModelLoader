//
// Created by matt on 22/11/18.
//
#include <string>
#include <ostream>
#include "Model.h"

int main (int argc, char** argv) {
    std::string filePath = "../test/ExampleModel4.mod";
    try {
        Model ExampleModel1(filePath);
        std::cout << "File loaded successfully. " 
            << ExampleModel1.getCells().size() << " cells, " 
            << ExampleModel1.getVertices().size() << " vertices & " 
            << ExampleModel1.getMaterials().size() << " materials." << std::endl;
    } catch (std::runtime_error &e) {
        throw e;
    }
    return 0;
}
