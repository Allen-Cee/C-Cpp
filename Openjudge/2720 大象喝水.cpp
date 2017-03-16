#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    float Pi=3.14159,h,r;
    int i=0;
    cin>>h>>r;
    float v=Pi*r*r*h;
    while(v*(++i)<20000);
    cout<<i;
    return 0;
}