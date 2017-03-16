#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<unistd.h>
using namespace std;

int main() {
    char plain[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
    string input;
    char text[201];
    while(1){
        cin>>input;
        if(input=="ENDOFINPUT") break;
        getchar();
        memset(text,'\0',201);
        gets(text);
        for(int i=0;text[i]!='\0';i++){
            if(text[i]>='A'&&text[i]<='Z') cout<<plain[text[i]-'A'];
            else cout<<text[i];
        }
        cout<<endl;
        cin>>input;
    }
    return 0;
}