//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
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

int main(){
    int n;
    cin>>n;
    while(n-->0){
        unsigned int p,q,r,i;
        cin>>p>>q>>r;
        for(i=2;i<17;i++){
            int a=sysTrans(p,i),b=sysTrans(q,i),c=sysTrans(r,i);
            if(a==-1||b==-1||c==-1) continue;
            if(a*b==c) break;
        }
        if(i==17) cout<<0<<endl;
        else cout<<i<<endl;
    }
    return 0;
}
