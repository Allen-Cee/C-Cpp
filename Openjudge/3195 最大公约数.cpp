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

int o[20];
char h[20];

int main(){
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int a,b,t,r,leno=0,lenh=0;
    scanf("%d%d",&a,&b);
    if(a>b) t=b;
    else t=a;
    for(r=t;r>0;r--) if(a%r==0&&b%r==0) break;
    for(int oct=r;oct>0;oct/=8){
        o[leno++]=oct%8;
        oct-=oct%8;
    }
    for(int hex=r;hex>0;hex/=16){
        h[lenh++]=(hex%16>9)?(hex%16-10+'a'):(hex%16+'0');
        hex-=hex%16;
    }
    printf("%d 0x",r);
    for(int i=lenh-1;i>=0;i--) printf("%c",h[i]);
    printf(" 0");
    for(int i=leno-1;i>=0;i--) printf("%d",o[i]);
    printf("\n");
    return 0;
}
