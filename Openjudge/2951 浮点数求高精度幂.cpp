#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int s[7],m[300],r[300],dot=0,dots=0;

inline void printResult(int length){
    int t=0;
    for(int i=length-1;i>=0;i--){
        if(r[i]!=0||i<dots) t=1;
        if(r[i]==0&&t==0){
            if(r[length-1]==0){
                if(length==1){
                    cout<<0;
                    break;
                }
                else continue;
            }
            continue;
        }
        if(t==1){
            if(i==dots-1) cout<<".";
            cout<<r[i];
        }
    }
    cout<<"\n";
}

void multiply(int n){
    for(int i=0;m[i]!=-1;i++) m[i]=-1;
    for(int i=0;s[i]!=-1;i++){
        for(int j=0;r[j]!=-1;j++){
            if(m[i+j]>-1) m[i+j]+=s[i]*r[j];
            else m[i+j]=s[i]*r[j];
        }
    }
    for(int i=0;m[i]!=-1;i++){
        if(m[i]>9){
            if(m[i+1]>-1) m[i+1]+=m[i]/10;
            if(m[i+1]==-1) m[i+1]=m[i]/10;
            m[i]%=10;
        }
    }
    int t=0,length=0,sub=0;
    dots+=dot;
    for(int i=0;i<300;i++) r[i]=-1;
    for(int i=0;m[i]!=-1;i++){
        if(m[i]!=0||i>=dots) t=1;
        if(t==0&&m[i]==0&&i<dots) sub++;
        if(t==1){
            r[length]=m[i];
            length++;
        }
    }
    dots-=sub;
    if(n==1) printResult(length);
}

int main() {
    int n;
    char sc[7];
    while(cin>>sc>>n){
        for(int i=0;i<7;i++) s[i]=-1;
        for(int i=0;i<300;i++){
            r[i]=-1;
            m[i]=-1;
        }
        int j=0;
        for(int i=0;sc[i]!='\0';i++){
            if(sc[i]!='.'){
                s[j]=sc[i]-'0';
                j++;
            }
            else dot=i;
        }
        dot=j-dot;
        dots=dot;
        for(int i=j-1;i>=0;i--) r[j-1-i]=s[i];
        int t=0,sub=0,length=0;
        for(int i=0;i<7;i++) s[i]=-1;
        for(int i=0;r[i]!=-1;i++){
            if(r[i]!=0||i>=dots) t=1;
            if(r[i]==0&&t==0&&i<dots) sub++;
            if(t==1){
                s[length]=r[i];
                length++;
            }
        }
        dots-=sub;
        dot=dots;
        for(int i=0;i<7;i++) r[i]=-1;
        for(int i=0;s[i]!=-1;i++) r[i]=s[i];
        if(n==1) printResult(length);
        while(--n>0) multiply(n);
    }
    return 0;
}