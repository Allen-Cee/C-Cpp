#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    int Fibonacci[21];
    Fibonacci[0]=1;
    Fibonacci[1]=1;
    for(int i=2;i<21;i++){
        Fibonacci[i]=Fibonacci[i-1]+Fibonacci[i-2];
    }
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    for(int i=0;i<n;i++){
        cout<<Fibonacci[data[i]-1]<<endl;
    }
    return 0;
}