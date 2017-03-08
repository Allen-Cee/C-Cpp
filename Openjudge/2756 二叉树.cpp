#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int m=1;
    while(a>=pow(2,m)) ++m;
    int x[m];
    int n=1;
    while(b>=pow(2,n)) ++n;
    int y[n];
    for(int i=0;a>=1;i++){
        x[i]=a;
        if(a%2==0) a/=2;
        else if(a%2==1) a=(a-1)/2;
    }
    for(int i=0;b>=1;i++){
        y[i]=b;
        if(b%2==0) b/=2;
        else if(b%2==1) b=(b-1)/2;
    }
    int result=1;
    while(x[m-1]==y[n-1]&&m>=1&&n>=1){
        result=x[m-1];
        --m;
        --n;
    }
    cout<<result<<endl;
    return 0;
}