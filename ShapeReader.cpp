
/**********************************************************
 *SN Comment:On to the implementation file!!
 **********************************************************/
#include "ShapeReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
/*SN Comment: The code above is simple including all the
necessary libaray's and header files for the program's
 execution*/


ShapeReader::ShapeReader() {
    height = 0;
    width = 0;
    sucessfully_read = false;
}
//SN Comment: Constructor for ShapeReader Object with default values

int ShapeReader::getHeight() const {
    return height;
}
//SN Comment:function to return the height of the Shape Reader
int ShapeReader::getWidth() const {
    return width;
}
//SN Comment:function to return the width of the Shape Reader

bool ShapeReader::write(std::ostream& output) {
    //SN Comment:this boolean type is comparing the shape inserted against the default values
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            output << '0';
            if(j < width - 1){
                output << ' ';
            }else{
                //SN Comment: uses a fun and fancy nested for loop to read the height & width of the
                //SN Comment: rectangle
                output << std::endl;
            }
        }
    }
    return true;
}

bool ShapeReader::readFile(const std::string& filename) noexcept(false){
    //SN Comment:reading the input file and setting const string & filename
    std::ifstream input_file (filename);
    //SN Comment:Yea input file stream!  just reading the file name
    std::string temp_line;
    //SN Comment:initializing string variable 'temp_line'
    std::stringstream temp_string_stream;
    //SN Comment:Yea string stream! setting temporary string stream
    char temp_char;
    //SN Comment: sets temporary char variable
    int current_row_counter = 0;
    //SN Comment: Now we're setting our row counters
    int initial_width = -1;
    //SN Comment: initializing a default width
    int current_height = 0;
    //SN Comment: initializing a default height
    char error[256];
    //SN Comment:error char type array at 256

    if (input_file.is_open()){
        //SN Comment: If statement to ensure correct file type is open
        while(getline(input_file, temp_line)) {
            //SN Comment:using getline to pull each row of data
            temp_string_stream.clear();
            //SN Comment: clears the temporary sting variable
            temp_string_stream.str(temp_line);
            //SN Comment:sets temporary string variable at temp_line from the file
            current_row_counter = 0;
            //SN Comment:sets row counter variable to 0
            while(!temp_string_stream.eof()){
                //SN Comment: as long at the row is not at the end of the file... the next code will happen
                temp_string_stream >> temp_char;
                //SN Comment:piping out the string stream to temporary char variable
                if(temp_char != '0'){
                    //SN Comment:If the temp_char variable is not at zero...more things will happen (below)
                    std::snprintf(error,256,"Bad character in input file. (%c)",temp_char);
                    //SN Comment:Here's where this gets fun: if ALL the above conditions are true, we're
                    //SN Comment:going to print that ther is a bad character in the input file
                    throw std::runtime_error(error);
                    //SN Comment:this throws the exception (when all above statements are true
                }
                // Correct for an off-by-one error
                if(!temp_string_stream.eof()){
                    current_row_counter++;
                    //SN Comment:As long as we're not at the end of the file, the rows will increment
                    //SN Comment:... accumulating a sum of the total rows
                }
            }

            if(initial_width == -1){
                initial_width = current_row_counter;
                //SN Comment:if the initial row counter hits the defalut value, we're copying the
                //SN Comment:initial_width variable to the current_row_counter varialb
            }else{
                //SN Comment:... if the above is false...2 things might happen
                if(current_row_counter != initial_width){
                    //SN Comment: but first, we'll check to see fi the row count does not equal the initial width
                    std::snprintf(error,256,"Mismatched widths at row %i. (%i != %i)", current_height,initial_width,current_row_counter);
                    //SN Comment:if so... we're throwing a runtime error using print format to show exactly what's wrong
                    throw std::runtime_error(error);
                    //SN Comment:the official runtime error throw
                }
            }
            current_height++;
            //SN Comment:If all elements are true, we're gonna increment the height accumulator
        }
        this->width = initial_width;
        //SN Comment:zipping the initial width to the width variable in main.cpp
        this->height = current_height;
        //SN Comment:zipping the height over to main.cpp too
        input_file.close();
        //SN Comment:close that file!!!
    }else{
        throw std::runtime_error("File could not be opened");
        //SN Comment:harkening back to row 68, throw the run time error if the file can't be opened
    }
    sucessfully_read = true;
    //SN Comment:setting boolean value to true if read properly
    return true;
    //SN Comment:FINAL (true) return statement of this block of code
}

int ShapeReader::setHeight(int new_height) {
    //SN Comment: New object!!!
    if(new_height > 0){
        //if the new height is greater than 0 (i.e. default)...

        height = new_height;
        //SN Comment: zip in the new height!
    }else{
        std::cout << "Bad width given" << std::endl;
        //SN Comment:if we got a negative height... something has wrong and push out this error
    }
    return height;
    //SN Comment: returns the height ajusted to the correct input
}

int ShapeReader::setWidth(int new_width) {
    //SN Comment:New object!!
    if(new_width > 0){
        //SN Comment: if the width is greater than 0...
        width = new_width;
        //SN Comment: update with the new width!
    }
    return width;
    //SN Comment: return the new width!
}
//SN Comment:  On to comment the header file!!!





