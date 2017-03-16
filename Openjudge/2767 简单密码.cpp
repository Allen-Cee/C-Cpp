#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
using namespace std;

int main() {
    char s[200];
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='F'&&s[i]<='Z') cout<<(char)(s[i]-5);
        else if(s[i]>='A'&&s[i]<='E') cout<<(char)(s[i]+21);
        else cout<<s[i];
    }
    return 0;
}