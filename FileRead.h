#ifndef FILEREAD_H
#define FILEREAD_H

#include <bits/stdc++.h>
#include "LogLine.h"

using namespace std;

class FileRead {
private:
    string file_Name;
    vector<LogLine> dataset;

public:
    FileRead(string input);

    void readFile();

    vector<LogLine> getDataset();
};
#endif