#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s[1010];
    int num=0,tmp=0;
    cin>>s;
    for(int i=0;s[i]!='\0';i++) num+=s[i]-'0';
    while(num>9){
        tmp=0;
        while(num>0){
            tmp+=num%10;
            num/=10;
        }
        num=tmp;
    }
    cout<<num<<endl;
    return 0;
}