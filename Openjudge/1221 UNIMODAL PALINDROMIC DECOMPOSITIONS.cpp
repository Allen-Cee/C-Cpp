//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long num[300][300];

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    for(int i=0;i<300;++i){
        num[i][i]=1;
        num[0][i]=1;
    }
    for(int i=2;i<300;++i){
        for(int j=i-1;j>=1;--j){
            num[i][j]+=num[i][j+1]+((i>=2*j)?num[i-2*j][j]:0);
        }
    }
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        printf("%d %lld\n",n,num[n][1]);
    }
    return 0;
}
