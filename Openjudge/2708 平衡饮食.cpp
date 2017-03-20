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
    float nu[10][3]={
        {7.5,0.75,78},
        {10,1.25,75},
        {1.5,0.19,4.28},
        {35,18,42},
        {5.0,5.0,0.6},
        {16.5,28.8,1.05},
        {17.7,20.33,4.06},
        {14.9,0.8,0.93},
        {0,100,0},
        {0.85,0.5,8}
    };
    float f[10],h[3]={0,0,0},sum=0;
    for(int i=0;i<10;i++){
        scanf("%f",&f[i]);
        for(int j=0;j<3;j++){
            if(i==4) h[j]+=f[i]*nu[i][j];
            else h[j]+=f[i]/100*nu[i][j];
        }
    }
    h[0]*=4.1;
    h[1]*=9.3;
    h[2]*=4.1;
    sum+=h[0]+h[1]+h[2];
    if(h[0]/sum>=0.14&&h[0]/sum<=0.16&&h[1]/sum>=0.3&&h[1]/sum<=0.35&&h[2]/sum>=0.49&&h[2]/sum<=0.56) printf("yes\n");
    else printf("no\n");
    return 0;
}
