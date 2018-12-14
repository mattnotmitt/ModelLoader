//
// Created by matt on 22/11/18.
//
#include <string>
#include <ostream>
#include <array>
#include "Model.h"

int main (int argc, char** argv) {
    std::array<std::array<std::string, 2>, 4> testFiles = {{
            {"../test/ExampleModel1.mod", "outfile1.mod"},
            {"../test/ExampleModel2.mod", "outfile2.mod"},
            {"../test/ExampleModel3.mod", "outfile3.mod"},
            {"../test/ExampleModel4.mod", "outfile4.mod"},
    }};
    for (auto const& test: testFiles) {
        std::string infilePath = test[0];
        std::string outfilePath = test[1];
        try {
            std::cout << "INFO | Loading " << infilePath << "." << std::endl;
            Model ExampleModel(infilePath);
            std::cout << "INFO | File " << infilePath << " loaded successfully. "
                      << ExampleModel.getCells().size() << " cells, "
                      << ExampleModel.getVertices().size() << " vertices & "
                      << ExampleModel.getMaterials().size() << " materials." << std::endl;
            ExampleModel.saveModel(outfilePath);
            std::cout << "INFO | Saved copy of model to " << outfilePath << "." << std::endl << std::endl;
        } catch (std::runtime_error &e) {
            throw e;
        }
    }
    return 0;
}
