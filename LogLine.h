#ifndef LOGLINE_H
#define LOGLINE_H

#include <bits/stdc++.h>
#include "TimeParse.h"

using namespace std;

class LogLine {
private:
    string mDate;
    map<string, int> mTimeMap;
    string mProcessId;
    string mThreadId;
    string mLogLevel; 
    string mLogMessage;

public:
    LogLine(string line);

    void doParsing(string input);
    void setMemberVariableValues(string input, int sc);

    string getDate();
    map<string, int> getTime();
    string getProcessId();
    string getThreadId();
    string getLogLevel();
    string getLogMessage();
};
#endif