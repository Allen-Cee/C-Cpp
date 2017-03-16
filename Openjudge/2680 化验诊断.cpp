#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    string sex;
    float wbc,rbc;
    int hgb,hct,plt,result;
    while(n-->0){
        result=0;
        cin>>sex>>wbc>>rbc>>hgb>>hct>>plt;
        if(wbc<4.0||wbc>10.0) result++;
        if(rbc<3.5||rbc>5.5) result++;
        if(plt<100||plt>300) result++;
        if(sex=="male"){
            if(hgb<120||hgb>160) result++;
            if(hct<42||hct>48) result++;
        }
        else if(sex=="female"){
            if(hgb<110||hgb>150) result++;
            if(hct<36||hct>40) result++;
        }
        if(result==0) cout<<"normal"<<endl;
        else cout<<result<<endl;
    }
    return 0;
}