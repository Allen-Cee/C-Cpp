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
    int n;
    scanf("%d",&n);
    int c[n],g[n],sc=0;
    float sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        sc+=c[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&g[i]);
        if(g[i]>=90) sum+=c[i]*4.0;
        if(g[i]>=85&&g[i]<=89) sum+=c[i]*3.7;
        if(g[i]>=82&&g[i]<=84) sum+=c[i]*3.3;
        if(g[i]>=78&&g[i]<=81) sum+=c[i]*3.0;
        if(g[i]>=75&&g[i]<=77) sum+=c[i]*2.7;
        if(g[i]>=72&&g[i]<=74) sum+=c[i]*2.3;
        if(g[i]>=68&&g[i]<=71) sum+=c[i]*2.0;
        if(g[i]>=64&&g[i]<=67) sum+=c[i]*1.5;
        if(g[i]>=60&&g[i]<=63) sum+=c[i]*1.0;
    }
    float GPA=(float)sum/sc;
    printf("%.2f\n",GPA);
    return 0;
}