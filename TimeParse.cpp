#include "TimeParse.h"
#include <iostream>

using namespace std;

TimeParse::TimeParse(string line)
{
    doParsing(line);
}
void TimeParse::doParsing(string input)
{
    int set_count =0, startIndex =0;
    string word;
    for(int i=0;i<input.length();i++)
    {
        if(input[i] ==':'){
            word = input.substr(startIndex,i-1);
            startIndex=i+1;
            set_count++;  
        }
            setMemberVariableValues(word,set_count);
    }
}
void TimeParse::setMemberVariableValues(string input, int sc)
{
    switch (sc)
    {
        case 1 : 
            hour = stringToInt(input);
            break;
        case 2 : 
            minute = stringToInt(input);
            break;
        case 3 : 
            second = stringToInt(input);
            break;
        case 4 : 
            millisecond = stringToInt(input);
            break;
        default:
            cout<<"Class TimeParse : Function setMemberVariableValues : Getting into default section of switch case : check sc variable value "<<endl;
            break;
    }
}
int TimeParse::stringToInt(string input)
{
    int output = 0;
    for(int i=0;i<input.length();i++)
    {
        output = output * 10 + input[i];
    }
    return output;
}
        
int TimeParse::getHour()
{
    return hour;
}
int TimeParse::getMinute()
{
    return minute;
}
int TimeParse::getSecond()
{
    return second;
}
int TimeParse::getMillisecond()
{
    return millisecond;
}


