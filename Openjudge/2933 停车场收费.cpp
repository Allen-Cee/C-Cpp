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

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    float t=0,f=0;
    while(scanf("%f",&t)!=EOF){
        if(t<=3) f=5;
        else f=5+(t-3)*2;
        if(f>40) f=40;
        printf("%.2f\n",f);
    }
    return 0;
}
