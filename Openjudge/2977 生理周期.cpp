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

inline int max(int a,int b,int c){
    if(a>=b&&a>=c) return a;
    if(b>=a&&b>=c) return b;
    return c;
}

int main() {
    int p,e,i,d;
    cin>>p>>e>>i>>d;
    while(p>=23) p-=23;
    while(e>=28) e-=28;
    while(i>=33) i-=33;
    while(p<=d) p+=23;
    while(p!=e||p!=i||e!=i||p<=d){
        while(p<max(p,e,i)) p+=23;
        while(e<max(p,e,i)) e+=28;
        while(i<max(p,e,i)) i+=33;
    }
    int day=p-d;
    cout<<day<<endl;
    return 0;
}