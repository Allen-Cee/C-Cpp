#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int a=1;a<=n;a++)
        for(int b=2;b<=a;b++)
            for(int c=b;c<=a;c++)
                for(int d=c;d<=a;d++)
                    if(a*a*a==b*b*b+c*c*c+d*d*d) cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
    return 0;
}