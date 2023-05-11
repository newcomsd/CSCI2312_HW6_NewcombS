/**********************************************************
 * Hey Matt!
 * For this assignment, all my comments begin with:
 * SN Comment:
 *
 * Notably, I ran out of time to compete the full assignment
 * and I was only able to commment the code.
 *
 * I started comment with the main file, then the
 * implementation file, and ended with the header file.
 *
 * ...maybe over the summer I'll figure out the triangle
 * implementation :-)
 *
 * Thanks for the extra credit, the fun task, and the
 * killer diller C++ semester!!
 **********************************************************/

#include <iostream>
#include "ShapeReader.h"
#include <stdexcept>
#include <fstream>
#include <vector>
/*SN Comment: The code above is simple including all the
necessary libaray's and header files for the program's
 execution*/


struct basicRect{
    int height;
    int width;
};
//SN Comment: creating a global structure for the height & width of the square

struct basicTri{
    int height;
    int width;
    // triangle type:
    // 1 -> Isosceles (Our version of equilateral)
    // 2 -> Right triangle (Top heavy)
    // 3 -> Right Triangle (Bottom heavy)
    int triangle_type;
};
//SN Comment: global structure for triangle recognition

bool test_file(std::string filename, bool expected_outcome, basicRect r = {-1,-1})
/*SN Comment: setting a bool, True/False to pull "filename" string, compare against an
'expected_outcome' variable with a basicRectangle set with default height & width
of -1, & -1*/
{
    std::cout << "TESTING " << filename << std::endl;
    //SN Comment: a nice output to the reader that the file is 'testing'

    ShapeReader tester = ShapeReader();
    //SN Comment: Calling ShapReader class from the ShapeReader implementation file
    bool pass = false;
    //SN Comment: setting pass variable to 'false' for error testing/looping
    try{
        tester.readFile(filename);
        //SN Comment: Opening/Reading
        printf("File read successfully with the following properties. \n");
        //SN Comment: Nice print statement showing a successfully read file
        printf("Height: %i, Width: %i \n",tester.getHeight(),tester.getWidth());
        //SN Comment: pulling the height and width from the tester file
        tester.write(std::cout);
        //SN Comment: printing out the rectangle
        pass = true;
        //SN Comment: switches the 'pass' varaible to true to continue with program
    }catch(std::runtime_error& e){
        //SN Comment: catch function for a run-time or file error
        std::cout << "Error from file: " << filename << std::endl;
        //SN Comment: file error message
        std::cout << e.what() << std::endl;
        //SN Comment: throws error comment specifying error
    }
    if(pass == expected_outcome){
        //SN Comment: clasic 'if' statement if the file was properly read and pulled
        if(pass){
            //SN Comment: NESTED if statement if pass remains true
            if(r.height == tester.getHeight() && r.width == tester.getWidth()){
                //SN Comment: ANOTHER nested 'if' comparing the file results & the tester results
                std::cout << "Shape was loaded correctly from file: " << filename << std::endl;
                //SN Comment: A nice message to the user showing a successful loaded file
                std::cout << "TEST PASSED" << std::endl;
                //SN Comment: show a successful passed test
                return true;
                //SN Comment: Return's 'true' for successful read
            }else{
                std::cout << "System did not properly interpret file: " << filename << std::endl;
                //SN Comment: Files aren't always read properly, this statement pulls if there
                //SN Comment: is an error in the file that can't be read
                std::cout << "TEST FAILED" << std::endl;
                //SN Comment: Mildly obnoxious statement to the user showing a failed, read file
                return false;
                //SN Comment: False statement ends the next program steps
            }
        }else{
            std::cout << "TEST PASSED" << std::endl;
            //SN Comment: If the 3rd nested statement returns true, the program jumps
            //SN Comment: to this middle if statement to show the test was passed
            return true;
        }
    }
    std::cout << "System did not properly interpret file: " << filename << std::endl;
    //SN Comment: Files aren't always read properly, this statement pulls if there
    //SN Comment: is an error in the file that can't be read
    std::cout << "TEST FAILED" << std::endl;
    //SN Comment: Mildly obnoxious statement to the user showing a failed, read file
    return false;
    //SN Comment: Ends program
}

void printTestReport(std::ostream& output, std::vector<bool> report){
    //SN Comment: void function that pulls oustream and T/F vector for the error report

    output << "=================================================" << std::endl;
    output << "ERROR REPORT" << std::endl;
    //SN Comment: The two lines above begin building the error report
    int count_pass = 0;
    //SN Comment: Set count_pass integer variable to 0

    for(int i = 0; i < report.size(); i++){
        output << "TEST [" << i << "]: ";
        //SN Comment:a fun little loop that builds a report showing successful
        //SN Comment: and failed tests over 3 iterations
        if(report[i] == true){
            output << "Passed! :)" << std::endl;
            count_pass++;
            //SN Comment:showing a cute 'passed' statement for each test
        }else{
            output << "Failed. :(" << std::endl;
            //SN Comment: showing a failed statement when the test didn't pass
        }
    }
    output << "TOTAL PASSED: " << count_pass << "/" << report.size() << std::endl;
    //SN Comment:fila report message showing pass/failed summary
    if(count_pass == report.size()){
        output << "ALL TESTS PASSED!" << std::endl;
        //SN Comment:if all tests passed: horray!!! exciting 'pass' statement!
    }
    output << "=================================================" << std::endl;
    //SN Comment:Nice way to end the report

}

void unitTestShapeReader(){
    //SN Comment:Here's where the magic happens: void function that builds a handful of
    //SN Comment:bool-type vectors, and variables for the program comparrisons
    std::vector<bool> error_report;
    //SN Comment: Sending a bool value via a vector to the error report

    bool current_test;
    //SN Comment: Another bool value for 'current-test' variable
    basicRect r1 = {3,7};
    //SN Comment:for the basic rectangle, setting height & width to 3 by 7...overiding
    //SN Comment: default values at -1 and -1
    current_test = test_file("../test_rect.txt", true, r1);
    //SN Comment:creates test file to compare if the expected outcome (aka a rectangle)
    //SN Comment:returns true, and then builds r1
    error_report.push_back(current_test);
    //SN Comment:collects the current test value for the error report

    std::cout << std::endl;
    //SN Comment:  creates a new line
    current_test = test_file("../test_rect_bad.txt", false);
    //SN Comment: pushing back test results of rectangle reads 'false'
    error_report.push_back(current_test);
    //SN Comment: sends error/false value to the error report

    std::cout << std::endl;
    //SN Comment:New line!

    ShapeReader tester = ShapeReader();
    //SN Comment: intializes the ShapeReader object
    tester.setHeight(20);
    //SN Comment:sets object height to 20
    tester.setWidth(30);
    //SN Comment: sets object width to 30
    std::ofstream new_file("../generated_rect.txt");
    //SN Comment:create outstream for object data
    tester.write(new_file);
    //SN Comment:writes data to new_file
    basicRect r2 = {20,30};
    //SN Comment: set r2 to a height of 20 and width of 30
    current_test = test_file("../generated_rect.txt", true, r2);
    //SN Comment: test file to ensure properly generated output file
    error_report.push_back(current_test);
    //SN Comment: collect T/F value if file was successfully built

    std::cout << std::endl;
    //SN Comment:new line!

    printTestReport(std::cout,error_report);
    //SN Comment:test report function for error report

}

int main() {

    unitTestShapeReader();
    //SN Comment:The special main function creating the unitTestShape Reader
    return 0;
}
//SN Comment: Next, head to the implementation file for more comments!
