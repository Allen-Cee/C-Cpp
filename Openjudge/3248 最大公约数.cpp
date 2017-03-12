//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<memory.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int a,b;
    while(cin>>a>>b){
        if(a>b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        int i;
        for(i=a;i>0;i--) if(a%i==0&&b%i==0) break;
        cout<<i<<endl;
    }
    return 0;
}
