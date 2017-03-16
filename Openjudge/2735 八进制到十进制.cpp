#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    int addup=0;
    cin>>n;
    for(int i=0;n;i++){
        addup+=n%10*pow(8,i);
        n/=10;
    }
    cout<<addup<<endl;
    return 0;
}