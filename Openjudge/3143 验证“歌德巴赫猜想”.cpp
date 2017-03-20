//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

bool prime(int n){
    bool b=1;
    for(int i=2;i<=sqrt(n);i++) if(n%i==0){
        b=0;
        break;
    }
    return b;
}

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int in;
    scanf("%d",&in);
    if(in<6||in%2==1) printf("Error!\n");
    else for(int i=2;i<=in/2;i++) if(prime(i)&&prime(in-i)) printf("%d=%d+%d\n",in,i,in-i);
    return 0;
}
