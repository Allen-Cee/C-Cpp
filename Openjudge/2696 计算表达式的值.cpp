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
    while(n-->0){
        int a,b;
        char op[4];
        scanf("%d%s%d",&a,op,&b);
        switch (op[0]) {
            case 'm':
                if(op[1]=='u') printf("%d\n",a*b);
                else printf("%d\n",a%b);
                break;
            case 'a':
                printf("%d\n",a+b);
                break;
            case 'd':
                printf("%d\n",a/b);
                break;
            case 's':
                printf("%d\n",a-b);
                break;
        }
    }
    return 0;
}