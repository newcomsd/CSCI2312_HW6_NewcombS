#include <iostream>
#include "ShapeReader.h"
#include <stdexcept>
#include <fstream>
#include <vector>

struct basicRect{
    int height;
    int width;
};

struct basicTri{
    int height;
    int width;
    // triangle type:
    // 1 -> Isosceles (Our version of equilateral)
    // 2 -> Right triangle (Top heavy)
    // 3 -> Right Triangle (Bottom heavy)
    int triangle_type;
};

bool test_file(std::string filename, bool expected_outcome, basicRect r = {-1,-1}){
    std::cout << "TESTING " << filename << std::endl;

    ShapeReader tester = ShapeReader();
    bool pass = false;
    try{
        tester.readFile(filename);
        printf("File read successfully with the following properties. \n");
        printf("Height: %i, Width: %i \n",tester.getHeight(),tester.getWidth());
        tester.write(std::cout);
        pass = true;
    }catch(std::runtime_error& e){
        std::cout << "Error from file: " << filename << std::endl;
        std::cout << e.what() << std::endl;
    }
    if(pass == expected_outcome){
        if(pass){
            if(r.height == tester.getHeight() && r.width == tester.getWidth()){
                std::cout << "Shape was loaded correctly from file: " << filename << std::endl;
                std::cout << "TEST PASSED" << std::endl;
                return true;
            }else{
                std::cout << "System did not properly interpret file: " << filename << std::endl;
                std::cout << "TEST FAILED" << std::endl;
                return false;
            }
        }else{
            std::cout << "TEST PASSED" << std::endl;
            return true;
        }
    }
    std::cout << "System did not properly interpret file: " << filename << std::endl;
    std::cout << "TEST FAILED" << std::endl;
    return false;
}

void printTestReport(std::ostream& output, std::vector<bool> report){

    output << "=================================================" << std::endl;
    output << "ERROR REPORT" << std::endl;
    int count_pass = 0;

    for(int i = 0; i < report.size(); i++){
        output << "TEST [" << i << "]: ";
        if(report[i] == true){
            output << "Passed! :)" << std::endl;
            count_pass++;
        }else{
            output << "Failed. :(" << std::endl;
        }
    }
    output << "TOTAL PASSED: " << count_pass << "/" << report.size() << std::endl;
    if(count_pass == report.size()){
        output << "ALL TESTS PASSED!" << std::endl;
    }
    output << "=================================================" << std::endl;

}

void unitTestShapeReader(){
    std::vector<bool> error_report;

    bool current_test;
    basicRect r1 = {3,7};
    current_test = test_file("../test_rect.txt", true, r1);
    error_report.push_back(current_test);

    std::cout << std::endl;
    current_test = test_file("../test_rect_bad.txt", false);
    error_report.push_back(current_test);

    std::cout << std::endl;

    ShapeReader tester = ShapeReader();
    tester.setHeight(20);
    tester.setWidth(30);
    std::ofstream new_file("../generated_rect.txt");
    tester.write(new_file);
    basicRect r2 = {20,30};
    current_test = test_file("../generated_rect.txt", true, r2);
    error_report.push_back(current_test);

    std::cout << std::endl;

    printTestReport(std::cout,error_report);

}

int main() {
    unitTestShapeReader();
    return 0;
}
