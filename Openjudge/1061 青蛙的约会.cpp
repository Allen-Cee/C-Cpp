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

long long minax(long long *a,long long *b){
    long long min=*a,max=*b;
    if(*a>*b){
        min=*a;
        max=*b;
    }
    long long icp=min;
    if(max%min==0) return max;
    for(int i=2;i<=icp;i++) if(icp%i==0&&max%i==0){
        icp/=i;
        max/=i;
        i--;
    }
    return max*min;
}

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    long long x,y,m,n,l,ma,mb,mix;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    long long tx=x,ty=y;
    if(tx==ty){
        printf("0\n");
        return 0;
    }
    ma=minax(&m,&l)/m;
    mb=minax(&n,&l)/n;
    mix=minax(&ma,&mb);
    for(int i=0;i<mix;i++){
        if(tx==ty){
            printf("%d\n",i);
            return 0;
        }
        tx+=m;
        ty+=n;
        if(tx>=l) tx%=l;
        if(ty>=l) ty%=l;
    }
    printf("Impossible\n");
    return 0;
}
