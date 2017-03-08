#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    for(int n=2;n<=1000;n++){
        int add=0,num=0,factor[40]={};
        for(int i=1;i<n;i++){
            if(n%i==0){
                add+=i;
                factor[num++]=i;
            }
        }
        if(add==n){
            cout<<n<<" its factors are ";
            for(int i=0;i<num;i++){
                if(i<num-1) cout<<factor[i]<<",";
                else if(i==num-1) cout<<factor[i]<<endl;
            }
        }
    }
    return 0;
}