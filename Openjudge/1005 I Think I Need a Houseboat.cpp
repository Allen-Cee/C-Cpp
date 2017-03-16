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

#define Pi 3.14159265

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int yr=0;
        float x,y;
        scanf("%f%f",&x,&y);
        while((yr*(100/Pi))<(x*x+y*y)) yr++;
        printf("Property %d: This property will begin eroding in year %d.\n",i,yr);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
