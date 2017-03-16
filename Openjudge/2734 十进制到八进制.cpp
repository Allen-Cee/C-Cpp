#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    int length=0;
    while(n>=pow(8,length)) ++length;
    int num[length];
    for(int i=0;i<length;i++){
        num[i]=0;
    }
    int power=length-1;
    for(int i=0;i<length;i++){
        while(n>=pow(8,power)){
            n-=pow(8,power);
            ++num[i];
        }
        --power;
    }
    for(int i=0;i<length;i++){
        cout<<num[i];
    }
    return 0;
}