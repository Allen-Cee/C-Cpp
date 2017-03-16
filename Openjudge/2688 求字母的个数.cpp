#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s[80];
    int num[5]={0,0,0,0,0};
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a') ++num[0];
        if(s[i]=='e') ++num[1];
        if(s[i]=='i') ++num[2];
        if(s[i]=='o') ++num[3];
        if(s[i]=='u') ++num[4];
    }
    for(int i=0;i<5;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}