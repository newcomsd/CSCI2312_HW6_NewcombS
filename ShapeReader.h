/**********************************************************
 *SN Comment:On to the header file!!
 **********************************************************/

#ifndef CSCI_2312_SHAPEREADER_SHAPEREADER_H
#define CSCI_2312_SHAPEREADER_SHAPEREADER_H

//SN Comment:  LOVE these guys!! They keep you clean and make sure your
//SN Comment: files are all in the same folder
#include <string>
#include <stdexcept>
//SN Comment: necessary pre-processor library's, classed and files.
class ShapeReader {
    //SN Comment: THE CLASS OBJECT!!!!
protected:
    //SN Comment: the protected items below are only partially private
    //SN Comment: ...he he... private...
    int height;
    //SN Comment: Object height
    int width;
    //SN Comment: Object width
    bool sucessfully_read;
    //SN Comment: boolean T/F statement for a successfully read object
public:
    //SN Comment: Here's all the public members...
    ShapeReader();
    //SN Comment: can't go far without a good constructor
    virtual bool readFile(const std::string& filename) noexcept(false);
    //SN Comment: super cool readfile virtual method
    virtual bool write(std::ostream& output);
    //SN Comment: another virtual function for the out stream reference  output
    int getHeight() const;
    //SN Comment: getHeight constant function variable
    int getWidth() const;
    //SN Comment: getWidth constant function variable
    int setHeight(int new_height);
    //SN Comment: the set Height function
    int setWidth(int new_width);
    //SN Comment: the set Width function
};

#endif //CSCI_2312_SHAPEREADER_SHAPEREADER_H
//SN Comment: end as long as everything is in the file!
