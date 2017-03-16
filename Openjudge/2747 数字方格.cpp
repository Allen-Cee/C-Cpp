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
    int n,max=0,a1=0,a2=0,a3=0;
    scanf("%d",&n);
    for(a1=n;a1>=0;a1--)
        for(a2=n;a2>=0;a2--)
            if((a1+a2)%2==0)
                for(a3=n;a3>=0;a3--)
                    if((a2+a3)%3==0&&(a1+a2+a3)%5==0&&max<(a1+a2+a3)) max=a1+a2+a3;
    printf("%d\n",max);
    return 0;
}
