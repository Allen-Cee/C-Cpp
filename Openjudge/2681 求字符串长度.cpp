#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s[100];
    char *p=s;
    gets(s);
    int i=0;
    while(*(p+i)!='\0') i++;
    cout<<i<<endl;
    return 0;
}