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
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n-->0){
        int num[5];
        for(int i=0;i<4;i++){
            scanf("%d",&num[i]);
            printf("%d ",num[i]);
        }
        if(num[0]==0||(num[3]-num[2]==num[1]-num[0])) printf("%d\n",num[3]+num[1]-num[0]);
        else printf("%d\n",num[3]*num[1]/num[0]);
    }
    return 0;
}
