#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int w,d[13]={0,12,31,28,31,30,31,30,31,31,30,31,30};
    cin>>w;
    for(int i=1;i<13;i++){
        w+=d[i];
        if(w%7==5) cout<<i<<endl;
    }
    return 0;
}