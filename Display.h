#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include "LogLine.h"

using namespace std;

class Display
{
    private:
    vector<LogLine> dataset;
    int hour, minute, second, millisecond;

    public:
    Display(vector<LogLine>& set);

    void printPV(string pid, string vid);
    void printTimeRange(string start, string end);
    void print(LogLine lobj);
    void doParsing(string input);
    void setMemberVariableValues(string input, int sc);
    int stringToInt(string input);

};
#endif