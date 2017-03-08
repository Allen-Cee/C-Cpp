#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s[4][80];
    int num[26]={};
    for(int n=0;n<4;n++){
        gets(s[n]);
        for(int i=0;s[n][i]!='\0';i++)
            if(s[n][i]>='A'&&s[n][i]<='Z') num[s[n][i]-'A']++;
    }
    int max=0;
    for(int i=0;i<26;i++)
        if(max<num[i]) max=num[i];
    while(max>0){
        for(int i=0;i<26;i++){
            if(num[i]>=max) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
        max--;
    }
    for(int i=0;i<26;i++)
        cout<<(char)('A'+i)<<" ";
    cout<<endl;
    return 0;
}