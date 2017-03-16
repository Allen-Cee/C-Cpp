#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char w[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main() {
    int d;
    while(cin>>d){
        if(d==-1) break;
        d++;
        int i,j=0,wk=(d+5)%7;
        for(i=2000;d>0;i++){
            if((i%4==0&&i%100!=0)||i%400==0) m[1]=29;
            else m[1]=28;
            for(j=0;j<12&&d>0;j++) d-=m[j];
        }
        i--;
        d+=m[j-1];
        printf("%d-%02d-%02d %s\n",i,j,d,w[wk]);
    }
    return 0;
}