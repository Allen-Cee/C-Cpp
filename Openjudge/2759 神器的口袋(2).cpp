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

int n,g[200],num[401];

int main(){
    freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&g[i]);
    for(int i=0;i<n;i++){
        int tmp=400-g[i];
        for(int j=tmp;j>=0;j--) if(num[j]){
            num[j+g[i]]+=num[j];
            num[j+g[i]]%=10000;
        }
        num[g[i]]++;
    }
    printf("%d\n",num[400]);
    return 0;
}
