#include <iostream>
#include <vector>
#include "FileRead.h"
#include "Display.h"

using namespace std;

int main(){
    string file_name;
    cout<<"Enter the File Name: "<<endl;
    cin>>file_name;
    int flag;
    while(1){
        
        cout<<"--------------------------------------"<<endl;
        cout<<"|         Filters Available          |"<<endl;
        cout<<"|         1. Pid and Vid (Flag = 1)  |"<<endl;
        cout<<"|         2. Time Range (Flag = 2)   |"<<endl;
        cout<<"--------------------------------------"<<endl;
        cin>>flag;

        FileRead file_object(file_name);
        file_object.readFile();
        vector<LogLine> dataset = file_object.getDataset();

        if(flag==1){
            string pid,vid;
            cout<<"Enter the value of PID and VID: "<<endl;
            cin>>pid>>vid;
            Display pobj(dataset);
            pobj.printPV(pid,vid);
        }
        else if(flag==2){
            string startTime, endTime;
            cout<<"Enter the value for start time and end time: "<<endl;
            cin>>startTime>>endTime;
            Display pobj(dataset);
            pobj.printTimeRange(startTime,endTime);
        }
        else{
            cout<<"Enter valid flag value as mentioned"<<endl;
        }

        return 0;
    }


    return 0;
}