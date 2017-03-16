#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s1[80],s2[80];
    gets(s1);
    gets(s2);
    for(int i=0;s1[i]!='\0';i++)
        if(s1[i]>='a'&&s1[i]<='z') s1[i]=(char)(s1[i]-32);
    for(int i=0;s2[i]!='\0';i++)
        if(s2[i]>='a'&&s2[i]<='z') s2[i]=(char)(s2[i]-32);
    for(int i=0;s1[i]!='\0'||s2[i]!='\0';i++){
        if(s1[i]>s2[i]){
            cout<<">"<<endl;
            return 0;
        }
        else if(s1[i]<s2[i]){
            cout<<"<"<<endl;
            return 0;
        }
    }
    cout<<"="<<endl;
    return 0;
}
