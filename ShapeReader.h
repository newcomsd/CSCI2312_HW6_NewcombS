

#ifndef CSCI_2312_SHAPEREADER_SHAPEREADER_H
#define CSCI_2312_SHAPEREADER_SHAPEREADER_H
#include <string>
#include <stdexcept>

class ShapeReader {
protected:
    int height;
    int width;
    bool sucessfully_read;
public:
    ShapeReader();
    virtual bool readFile(const std::string& filename) noexcept(false);
    virtual bool write(std::ostream& output);
    int getHeight() const;
    int getWidth() const;
    int setHeight(int new_height);
    int setWidth(int new_width);

};


#endif //CSCI_2312_SHAPEREADER_SHAPEREADER_H
