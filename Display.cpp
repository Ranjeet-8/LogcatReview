#include "Display.h"

using namespace std;

Display::Display(vector<LogLine>& set) : dataset(set) {}

void Display::printPV(string pid, string vid) {
    for(auto index : dataset)
    {
        if((index.getProcessId() == pid) && (index.getThreadId() == vid))
        {
            print(index);//write final print function
        }
    }
}
void Display::printTimeRange(string start, string end) {
    for(auto index : dataset)
    {
        doParsing(start);
        map<string,int> uTimemap;
        uTimemap = index.getTime();
        if((uTimemap.contains("Hour")) && (uTimemap.contains("Minute")) && (uTimemap.contains("Second")) && (uTimemap.contains("Millisecond")))
        {
            if((uTimemap["Hour"]>=hour) && (uTimemap["Minute"]>=minute) && (uTimemap["Second"]>=second) && (uTimemap["Millisecond"]>=millisecond))
            {
                doParsing(end);
                if((uTimemap["Hour"]<=hour) && (uTimemap["Minute"]<=minute) && (uTimemap["Second"]<=second) && (uTimemap["Millisecond"]<=millisecond))
                {
                    print(index);//write print final print function
                }
            }
        }
    }
}
void Display::print(LogLine lobj) {    
    map<string,int> time = lobj.getTime();

    cout<<lobj.getDate()<<" "<<time["Hour"]<<":"<<time["Minute"]<<":"<<time["Second"]<<"."<<time["Millisecond"]<<" "<<lobj.getProcessId()<<" "<<lobj.getThreadId()<<" "<<lobj.getLogLevel()<<" "<<lobj.getLogMessage()<<endl;
}
void Display::doParsing(string input) {
    int set_count =0, startIndex =0;
    string word;
    for(int i=0;i<input.length();i++)
    {
        if(set_count == 3) {
            word = input.substr(startIndex,(input.length()-1)-startIndex);
            set_count++;
            setMemberVariableValues(word,set_count);
            break;
        }
        if(input[i] ==':'){
            word = input.substr(startIndex,i-startIndex);
            startIndex=i+1;
            set_count++;  
            setMemberVariableValues(word,set_count);
        }
        
    }
}
void Display::setMemberVariableValues(string input, int sc) {
    switch (sc)
    {
        case 1 : {
            hour = stringToInt(input);
            break;
        }
        case 2 : { 
            minute = stringToInt(input);
            break;
        }
        case 3 : { 
            second = stringToInt(input);
            break;
        }
        case 4 : {
            millisecond = stringToInt(input);
            break;
        }
        default: {
            cout<<"Class TimeParse : Function setMemberVariableValues : Getting into default section of switch case : check sc variable value "<<endl;
            break;
        }
    }
}
int Display::stringToInt(string input) {
    int output = 0;
    for(int i=0;i<input.length();i++)
    {
        output = (output * 10) + (input[i]-48);
    }
    return output;
}
