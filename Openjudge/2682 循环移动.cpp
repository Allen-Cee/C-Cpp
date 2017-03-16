#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int num[n];
    for(int i=0;i<n;i++) cin>>num[i];
    for(int i=n-m;i<n;i++) cout<<num[i]<<" ";
    for(int i=0;i<n-m;i++) cout<<num[i]<<" ";
    return 0;
}