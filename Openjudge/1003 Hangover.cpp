#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
using namespace std;

int main() {
    float length=0,r;
    while(cin>>r){
        if(r==0) break;
        int i=0;
        length=0;
        while(length<r){
            ++i;
            length+=1.0/(i+1);
        }
        cout<<i<<" card(s)"<<endl;
    }
    return 0;
}