//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<memory.h>
using namespace std;

int n;

int MA(int *h,int *m,int l,int r){
    int max=0,tmp=r-l,num=0;
    for(int i=l;i<r;i++){
        if(h[i]<h[r]){
            if(m[i]==-1) m[i]=MA(h,m,l,i);
            tmp=m[i];
            num++;
            if(max<tmp) max=tmp;
        }
    }
    if(num==0) return 1;
    return max+1;
}

int MD(int *h,int *m,int l,int r){
    int max=0,tmp=r-l,num=0;
    for(int i=l+1;i<=r;i++){
        if(h[i]<h[l]){
            if(m[i]==-1) m[i]=MD(h,m,i,r);
            tmp=m[i];
            num++;
            if(max<tmp) max=tmp;
        }
    }
    if(num==0) return 1;
    return max+1;
}

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    scanf("%d",&n);
    int h[n],min=n;
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    for(int i=0;i<n;i++){
        int ma[n],md[n];
        memset(ma,-1,sizeof(ma));
        memset(md,-1,sizeof(md));
        int tmp=n-(MA(h,ma,0,i)+MD(h,md,i,n-1)-1);
        if(min>tmp) min=tmp;
    }
    printf("%d\n",min);
    return 0;
}
