#ifndef TIMEPARSE_H
#define TIMEPARSE_H

#include <bits/stdc++.h>

using namespace std;

class TimeParse {
private:
    int hour, minute, second, millisecond;

public:
    TimeParse(string line);

    void doParsing(string input);
    void setMemberVariableValues(string input, int sc);
    int stringToInt(string input);

    int getHour();
    int getMinute();
    int getSecond();
    int getMillisecond();
};
#endif