#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int num[200],n,length=1;
    for(int i=0;i<200;i++) num[i]=-1;
    num[0]=2;
    cin>>n;
    while(--n>0){
        length=0;
        for(int i=0;num[i]!=-1;i++) num[i]*=2;
        for(int i=0;num[i]!=-1;i++){
            if(num[i]>9){
                if(num[i+1]>-1) num[i+1]+=num[i]/10;
                if(num[i+1]==-1) num[i+1]=num[i]/10;
                num[i]%=10;
            }
            length++;
        }

    }
    for(int i=length-1;i>=0;i--) cout<<num[i];
    cout<<endl;
    return 0;
}