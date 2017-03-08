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
    int c[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&c[i][j]);
    for(int i=1;i<n-1;i++) for(int j=1;j<n-1;j++) if(c[i][j]+50<=c[i-1][j]&&c[i][j]+50<=c[i+1][j]&&c[i][j]+50<=c[i][j-1]&&c[i][j]+50<=c[i][j+1]) num++;
    printf("%d\n",num);
    return 0;
}