#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    string name,zone;
    int fe,cr,paper,max=0,total=0;
    char cadre,west;
    for(int i=0;i<n;i++){
        int prize=0;
        cin>>name>>fe>>cr>>cadre>>west>>paper;
        if(fe>80&&paper>=1) prize+=8000;
        if(fe>85&&cr>80) prize+=4000;
        if(fe>90) prize+=2000;
        if(fe>85&&west=='Y') prize+=1000;
        if(cr>80&&cadre=='Y') prize+=850;
        if(prize>max){
            max=prize;
            zone=name;
        }
        total+=prize;
    }
    cout<<zone<<"\n"<<max<<"\n"<<total<<endl;
    return 0;
}