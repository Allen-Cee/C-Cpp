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

bool nm[10],none=1;

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char c[31];
    scanf("%s",c);
    int len=(int)strlen(c),n[30],sum=0,sv[6]={1,3,2,-1,-3,-2};
    memset(n,0,sizeof(n));
    for(int i=len-1,j=0;i>=0;i--,j++){
        n[j]=c[i]-'0';
        sum+=n[j];
    }
    if(n[0]%2==0) nm[2]=1;
    if(sum%3==0) nm[3]=1;
    if((n[1]*10+n[0])%4==0) nm[4]=1;
    if(n[0]==5||n[0]==0) nm[5]=1;
    if(nm[2]&&nm[3]) nm[6]=1;
    if((n[2]*100+n[1]*10+n[0])%8==0) nm[8]=1;
    if(sum%9==0) nm[9]=1;
    sum=0;
    for(int i=0;i<len;i++) sum+=n[i]*sv[i%6];
    if(sum%7==0) nm[7]=1;
    for(int i=2;i<10;i++) if(nm[i]){
        printf("%d ",i);
        none=0;
    }
    if(none) printf("none");
    printf("\n");
    return 0;
}
