#ifndef FILEREAD_H
#define FILEREAD_H

#include <iostream>
#include <fstream>
#include <vector>
#include "LogLine.h"

using namespace std;

class FileRead
{
private:
    string file_Name;
    vector<LogLine> dataset;

public:
    FileRead(string input);

    void readFile();

    vector<LogLine> getDataset();
};



#endif