//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

int LIS(int i,int n,int *h,int *lis){
    if(lis[i]) return lis[i];
    int len=0;
    for(int j=i-1;j>=0;j--) if(h[i]>h[j]){
        if(lis[j]&&len<lis[j]) len=lis[j];
        else if(len<LIS(j,n,h,lis)) len=lis[j];
    }
    lis[i]=len+1;
    return lis[i];
}

int LDS(int i,int n,int *h,int *lds){
    if(lds[i]) return lds[i];
    int len=0;
    for(int j=i+1;j<n;j++) if(h[i]>h[j]){
        if(lds[j]&&len<lds[j]) len=lds[j];
        else if(len<LDS(j,n,h,lds)) len=lds[j];
    }
    lds[i]=len+1;
    return lds[i];
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int h[n],lis[n],lds[n],max=0;
    memset(lis,0,sizeof(lis));
    memset(lds,0,sizeof(lds));
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    for(int i=0;i<n;i++){
        int cn;
        if(lds[i]&&lis[i]) cn=lds[i]+lis[i]-1;
        else cn=LIS(i,n,h,lis)+LDS(i,n,h,lds)-1;
        if(max<cn) max=cn;
    }
    printf("%d\n",max);
    return 0;
}
