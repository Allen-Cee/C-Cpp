#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    float sum=0,num,price[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<10;j++){
            cin>>num;
            sum+=num*price[j];
        }
        printf("%.2f\n",sum);
    }
    return 0;
}