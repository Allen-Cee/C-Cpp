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
    char s[80];
    gets(s);
    if(s[0]>='a'&&s[0]<='z') s[0]=(char)(s[0]-32);
    for(int i=0;s[i+1]!='\0';i++) if((s[i]==' '||s[i]=='\t'||s[i]=='\r'||s[i]=='\n')&&s[i+1]>='a'&&s[i+1]<='z') s[i+1]=(char)(s[i+1]-32);
    puts(s);
    return 0;
}