#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int a;
    cin>>a;
    int addup=0;
    int num;
    for(int i=0;i<5;i++){
        cin>>num;
        if(num<a) addup+=num;
    }
    cout<<addup<<endl;
    return 0;
}