#include "FileRead.h"

FileRead::FileRead(std::string input) : file_Name(input) {}

void FileRead::readFile()
{
    std::ifstream infile(file_Name);
    if(!infile)
    {
        std::cout<<"Error in opening the file"<<std::endl;
    } 
    else
    {
        std::string line;
        while(getline(infile,line))
        {
            LogLine lobj(line);
            dataset.push_back(lobj);
        }
    }
}

std::vector<LogLine> FileRead::getDataset(){
    return dataset;
}
