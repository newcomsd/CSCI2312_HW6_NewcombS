
#include "ShapeReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

ShapeReader::ShapeReader() {
    height = 0;
    width = 0;
    sucessfully_read = false;
}

int ShapeReader::getHeight() const {
    return height;
}
int ShapeReader::getWidth() const {
    return width;
}

bool ShapeReader::write(std::ostream& output) {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            output << '0';
            if(j < width - 1){
                output << ' ';
            }else{
                output << std::endl;
            }
        }
    }
    return true;
}

bool ShapeReader::readFile(const std::string& filename) noexcept(false){
    std::ifstream input_file (filename);
    std::string temp_line;
    std::stringstream temp_string_stream;
    char temp_char;
    int current_row_counter = 0;
    int initial_width = -1;
    int current_height = 0;
    char error[256];

    if (input_file.is_open()){
        while(getline(input_file, temp_line)) {
            temp_string_stream.clear();
            temp_string_stream.str(temp_line);
            current_row_counter = 0;
            while(!temp_string_stream.eof()){
                temp_string_stream >> temp_char;
                if(temp_char != '0'){
                    std::snprintf(error,256,"Bad character in input file. (%c)",temp_char);
                    throw std::runtime_error(error);
                }
                // Correct for an off-by-one error
                if(!temp_string_stream.eof()){
                    current_row_counter++;
                }
            }

            if(initial_width == -1){
                initial_width = current_row_counter;
            }else{
                if(current_row_counter != initial_width){
                    std::snprintf(error,256,"Mismatched widths at row %i. (%i != %i)", current_height,initial_width,current_row_counter);
                    throw std::runtime_error(error);
                }
            }
            current_height++;
        }
        this->width = initial_width;
        this->height = current_height;
        input_file.close();
    }else{
        throw std::runtime_error("File could not be opened");
    }
    sucessfully_read = true;
    return true;
}

int ShapeReader::setHeight(int new_height) {
    if(new_height > 0){
        height = new_height;
    }else{
        std::cout << "Bad width given" << std::endl;
    }
    return height;
}

int ShapeReader::setWidth(int new_width) {
    if(new_width > 0){
        width = new_width;
    }
    return width;
}


