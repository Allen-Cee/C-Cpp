#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n%4==0){
        if(n%100==0){
            if(n%400==0) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        else cout<<"Y"<<endl;
    }
    else cout<<"N"<<endl;
    return 0;
}