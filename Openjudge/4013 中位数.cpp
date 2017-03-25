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

int CMP(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int num[n];
        for(int i=0;i<n;i++) scanf("%d",&num[i]);
        qsort(num,n,sizeof(num[0]),CMP);
        if(n%2) printf("%d\n",num[(n+1)/2-1]);
        else printf("%d\n",(num[n/2-1]+num[n/2])/2);
    }
    return 0;
}
