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
    int n[3]={361,529,784},max;
    scanf("%d",&max);
    for(int i=0;i<3;i++) if(n[i]<max) printf("%d ",n[i]);
    return 0;
}
