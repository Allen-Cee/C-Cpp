#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s[100];
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='A'&&s[i]<='Z') cout<<(char)(s[i]+32);
        else if(s[i]>='a'&&s[i]<='z') cout<<(char)(s[i]-32);
        else cout<<s[i];
    }
    return 0;
}