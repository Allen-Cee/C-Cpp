#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<unistd.h>
using namespace std;

int sysTrans(unsigned int a,unsigned int r){
    int re=0;
    for(int i=0;a>0;i++){
        if(a%10>=r) return -1;
        re+=(a%10)*pow(r,i);
        a/=10;
    }
    return re;
}

int main() {
    unsigned int p,q,r,i;
    cin>>p>>q>>r;
    for(i=2;i<17;i++){
        int a=sysTrans(p,i),b=sysTrans(q,i),c=sysTrans(r,i);
        if(a==-1||b==-1||c==-1) continue;
        if(a*b==c) break;
    }
    if(i==17) cout<<0;
    else cout<<i;
    return 0;
}
