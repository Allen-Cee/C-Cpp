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
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%3==0||i%5==0||i%10==3||i%10==5||i%100/10==3||i%100/10==5) continue;
        sum+=i*i;
    }
    printf("%d\n",sum);
    return 0;
}
