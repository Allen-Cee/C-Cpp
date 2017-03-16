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
    int a,n,num=0,add=0;
    scanf("%d%d",&a,&n);
    for(int i=0;i<n;i++){
        num+=a*pow(10,i);
        add+=num;
    }
    printf("%d\n",add);
    return 0;
}