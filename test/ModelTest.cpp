//
// Created by matt on 22/11/18.
//

#include "catch.hpp"
#include "Model.h"

SCENARIO("Can correctly load a model file", "[Model]") {
    GIVEN("A file path of a small model file") {
        std::string filePath = "../test/ExampleModel1.mod";
        WHEN("The file is parsed") {
            Model ExampleModel1(filePath);
            REQUIRE(ExampleModel1.getMaterials().size() == 2);
            REQUIRE(ExampleModel1.getCells().at(0)->getCellMaterial()->getName() == "copper");
        }
    }
    GIVEN("A file path of a large model file") {
        std::string filePath = "../test/ExampleModel2.mod";
        WHEN("The file is parsed") {
            Model ExampleModel2(filePath);
            // INFO(ExampleModel2.getCells().size())
            REQUIRE(ExampleModel2.getMaterials().size() == 2);
            REQUIRE(ExampleModel2.getCells().at(0)->getCellMaterial()->getName() == "cu");
        }
    }
}