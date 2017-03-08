#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n,m;
    float b,w;
    cin>>n;
    while(n-->0){
        cin>>m;
        b=50+(m/3.0);
        w=m/1.2;
        if(b<w) cout<<"Bike"<<endl;
        else if(b>w) cout<<"Walk"<<endl;
        else cout<<"All"<<endl;
    }
    return 0;
}