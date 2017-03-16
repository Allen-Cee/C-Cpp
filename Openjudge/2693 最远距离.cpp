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
    float poi[n][2];
    double dis=0,max=0;
    for(int i=0;i<n;i++) scanf("%f%f",&poi[i][0],&poi[i][1]);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            dis=pow(poi[i][0]-poi[j][0],2)+pow(poi[i][1]-poi[j][1],2);
            if(max<dis) max=dis;
        }
    printf("%.4f\n",sqrt(max));
    return 0;
}
