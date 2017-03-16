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
    char n[35];
    while(1){
        memset(n,'\0',35);
        scanf("%s",n);
        if(n[0]=='0') break;
        int num=0;
        for(int i=strlen(n)-1,len=1;i>=0;i--,len++) num+=(n[i]-'0')%10*(pow(2,len)-1);
        printf("%d\n",num);
    }
    return 0;
}
