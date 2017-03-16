#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    int addup=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        addup*=i;
    }
    cout<<addup<<endl;
    return 0;
}