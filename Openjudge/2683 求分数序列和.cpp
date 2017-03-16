#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    double a=1,b=2,ans=0,tmp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ans+=b/a;
        tmp=b;
        b+=a;
        a=tmp;
    }
    printf("%.4lf",ans);
    return 0;
}