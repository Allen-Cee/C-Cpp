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

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n-->0){
        int num,one=0;
        scanf("%d",&num);
        while(num>0){
            if(num%2==1) one++;
            num-=num%2;
            num/=2;
        }
        printf("%d\n",one);
    }
    return 0;
}
