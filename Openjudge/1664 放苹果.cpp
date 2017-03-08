#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int comb(int m,int n){
    if(m<=1||n<=1) return 1;
    if(n>m) return comb(m,m);
    return comb(m-n,n)+comb(m,n-1);
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int M,N;
        cin>>M>>N;
        cout<<comb(M,N)<<endl;
    }
    return 0;
}