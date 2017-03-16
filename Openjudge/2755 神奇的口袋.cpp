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
    int n,num=0;
    scanf("%d",&n);
    int good[n],max=pow(2,n);
    for(int i=0;i<n;i++) scanf("%d",&good[i]);
    for(int ci=1;ci<max;ci++){
        int add=0;
        for(int i=0;i<n;i++){
            if((ci>>i)&1) add+=good[i];
            if(add>40) break;
        }
        if(add==40) num++;
    }
    printf("%d\n",num);
    return 0;
}