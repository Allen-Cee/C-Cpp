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
    while(scanf("%d",&n)!=EOF){
        if(n%3==0&&n%5==0&&n%7==0) printf("3 5 7\n");
        else if(n%3==0&&n%5==0&&n%7!=0) printf("3 5\n");
        else if(n%3==0&&n%5!=0&&n%7==0) printf("3 7\n");
        else if(n%3!=0&&n%5==0&&n%7==0) printf("5 7\n");
        else if(n%3==0&&n%5!=0&&n%7!=0) printf("3\n");
        else if(n%3!=0&&n%5==0&&n%7!=0) printf("5\n");
        else if(n%3!=0&&n%5!=0&&n%7==0) printf("7\n");
        else if(n%3!=0&&n%5!=0&&n%7!=0) printf("n\n");
    }
    return 0;
}