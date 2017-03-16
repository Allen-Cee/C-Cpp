#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

inline int max(int a,int b,int c){
    if(a>=b&&a>=c) return a;
    if(b>=a&&b>=c) return b;
    return c;
}

int main() {
    int n=0;
    while(1){
        ++n;
        int p,e,i,d;
        cin>>p>>e>>i>>d;
        if(p==-1&&e==-1&&i==-1&&d==-1) break;
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
        //while(day>d+21252) day-=21252;
        cout<<"Case "<<n<<": the next triple peak occurs in "<<day<<" days."<<endl;
    }
    return 0;
}