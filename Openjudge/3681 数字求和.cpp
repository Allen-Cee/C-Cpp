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
    int a,n,sum=0;
    scanf("%d",&a);
    for(int i=0;i<5;i++){
        scanf("%d",&n);
        if(n<a) sum+=n;
    }
    printf("%d\n",sum);
    return 0;
}
