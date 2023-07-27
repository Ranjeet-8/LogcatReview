#include "LogLine.h"
#include <iostream>

using namespace std;

LogLine::LogLine(string line) {
    doParsing(line);
}

void LogLine::doParsing(string input) {
    int set_count = 0, startIndex = 0;
    string word;
    for (int i = 0; i < input.length(); i++) {
        if(set_count == 5) {
            word = input.substr(startIndex,(input.length()-1)-startIndex);
            set_count++;
            setMemberVariableValues(word, set_count);
            break;
        }
        if (input[i] == ' ') {
            word = input.substr(startIndex, i - startIndex);
            while(input[++i] == ' ');
            startIndex = i;
            set_count++;
            i--;
            setMemberVariableValues(word, set_count);
        }
    }
}

void LogLine::setMemberVariableValues(string input, int sc) {
    switch(sc) {
        case 1: {
            mDate = input;
            break;
        }
        case 2: {
            TimeParse tobj(input);
            mTimeMap["Hour"] = tobj.getHour();
            mTimeMap["Minute"] = tobj.getMinute();
            mTimeMap["Second"] = tobj.getSecond();
            mTimeMap["Millisecond"] = tobj.getMillisecond();
            break;
        }
        case 3: {
            mProcessId = input;
            break;
        }
        case 4: {
            mThreadId = input;
            break;
        }
        case 5: {
            mLogLevel = input;
            break;
        }
        case 6: {
            mLogMessage = input;
            break;
        }
        default: {
            cout << "Class LogLine: Function setMemberVariableValues: Getting into the default section of the switch case. Check sc variable value." << endl;
            break;
        }
    }
}

// Getter methods
string LogLine::getDate() {
    return mDate;
}

map<string, int> LogLine::getTime() {
    return mTimeMap;
}

string LogLine::getProcessId() {
    return mProcessId;
}

string LogLine::getThreadId() {
    return mThreadId;
}

string LogLine::getLogLevel() {
    return mLogLevel;
}

string LogLine::getLogMessage() {
    return mLogMessage;
}

