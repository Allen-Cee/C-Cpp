#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    float month[12];
    float addup=0;
    float average;
    for(int i=0;i<12;i++){
        cin>>month[i];
        addup+=month[i];
    }
    average=addup/12;
    printf("$%.2f",average);
    return 0;
}