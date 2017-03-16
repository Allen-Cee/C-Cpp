#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
using namespace std;

int main() {
    double e=1,m;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        m=i;
        for(int j=i-1;j>1;j--){
            m*=j;
        }
        e+=1/m;
    }
    printf("%.10f",e);
    return 0;
}