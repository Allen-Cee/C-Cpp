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
    long num=1;
    for(int i=2;i<=n;i++) num*=i;
    printf("%ld\n",num);
    return 0;
}