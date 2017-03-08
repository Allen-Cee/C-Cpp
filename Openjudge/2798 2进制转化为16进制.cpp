#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n,p[4]={1,2,4,8};
    char s[10010],o[17]="0123456789ABCDEF";
    cin>>n;
    while(n-->0){
        int num=0,output[2510]={};
        scanf("%s",s);
        short i=strlen(s)-1;
        while(i>=0){
            for(int j=0;j<4&&i>=0;j++,i--) output[num]+=(s[i]-'0')*p[j];
            num++;
        }
        for(int len=num-1;len>=0;len--) cout<<o[output[len]];
        cout<<endl;
    }
    return 0;
}
