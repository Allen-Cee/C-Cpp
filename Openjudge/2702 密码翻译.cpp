#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    char s[80],num[10];
    gets(num);
    n=atoi(num);
    while(n-->0){
        gets(s);
        for(int i=0;s[i]!='\0';i++){
            if((s[i]>='a'&&s[i]<='y')||(s[i]>='A'&&s[i]<='Y')) cout<<(char)(s[i]+1);
            else if(s[i]=='z'||s[i]=='Z') cout<<(char)(s[i]-25);
            else cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}