#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s1[300],s2[300];
    int n1[300]={},n2[300]={},n[50000],len1=0,len2=0;
    for(int i=0;i<50000;i++) n[i]=-1;
    gets(s1);
    gets(s2);
    while(s1[len1]!='\0') len1++;
    while(s2[len2]!='\0') len2++;
    for(int i=len1-1;i>=0;i--) n1[len1-1-i]=s1[i]-'0';
    for(int i=len2-1;i>=0;i--) n2[len2-1-i]=s2[i]-'0';
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(n[i+j]==-1) n[i+j]=0;
            n[i+j]+=n1[i]*n2[j];
        }
    }
    int length=0;
    for(int i=0;n[i]!=-1;i++){
        if(n[i]>9){
            if(n[i+1]>-1) n[i+1]+=n[i]/10;
            if(n[i+1]==-1) n[i+1]=n[i]/10;
            n[i]%=10;
        }
        length++;
    }
    int t=0;
    for(int i=length-1;i>=0;i--){
        if(n[i]==0&&t==0){
            if(i==0){
                cout<<0;
                break;
            }
            else continue;
        }
        if(n[i]!=0) t=1;
        cout<<n[i];
    }
    cout<<endl;
    return 0;
}