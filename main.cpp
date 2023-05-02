#include <iostream>
#include "ShapeReader.h"
#include <stdexcept>


void test_file(std::string filename){
    ShapeReader tester = ShapeReader();
    try{
        tester.readFile(filename);
    }catch(std::runtime_error& e){
        std::cout << "Error from file: " << filename << std::endl;
        std::cout << e.what() << std::endl;
        return;
    }
    printf("File read successfully with the following properties. \n");
    printf("Height: %i, Width: %i \n",tester.getHeight(),tester.getWidth());
    tester.write(std::cout);
}

int main() {

    test_file("../test_rect.txt");
    std::cout << std::endl;
    test_file("../test_rect_bad.txt");


    return 0;
}
