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
    int a[3][3],b[3][3];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
    getchar();
    getchar();
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) scanf("%d",&b[i][j]);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) printf("%4d",a[i][j]+b[i][j]);
        printf("\n");
    }
    return 0;
}