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
    float w;
    char e;
    while(scanf("%f %c",&w,&e)!=EOF){
        float m=0.8;
        if(w>1) m+=(w-1)*0.5;
        if(e=='y') m+=2;
        printf("%g\n",m);
    }
    return 0;
}