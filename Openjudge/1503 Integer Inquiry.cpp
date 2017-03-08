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
    char s1[300],s2[300];
    gets(s1);
    int n[300],length=0;
    while(gets(s2)){
        if(s2[0]=='0'&&s2[1]=='\0') break;
        int n1[300]={},n2[300]={},len1=0,len2=0;
        memset(n,0,sizeof(int));
        for(int i=0;i<300;i++) n[i]=-1;
        while(s1[len1]!='\0') len1++;
        while(s2[len2]!='\0') len2++;
        for(int i=len1-1;i>=0;i--) n1[len1-1-i]=s1[i]-'0';
        for(int i=len2-1;i>=0;i--) n2[len2-1-i]=s2[i]-'0';
        for(int i=0;i<len1||i<len2;i++) n[i]=n1[i]+n2[i];
        length=0;
        for(int i=0;n[i]!=-1;i++){
            if(n[i]>9){
                if(n[i+1]>-1) n[i+1]+=n[i]/10;
                if(n[i+1]==-1) n[i+1]=n[i]/10;
                n[i]%=10;
            }
            length++;
        }
        int t=0,sn=0;;
        memset(s1,'\0',300);
        for(int i=length-1;i>=0;i--){
            if(n[i]==0&&t==0){
                if(i==0){
                    cout<<0;
                    break;
                }
                else continue;
            }
            if(n[i]!=0) t=1;
            s1[sn++]=(char)(n[i]+'0');
        }
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