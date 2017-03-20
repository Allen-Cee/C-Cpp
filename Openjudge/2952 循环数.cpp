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

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    //性质：长度len的循环数*(len+1)各位为9 且循环数个位数和能被9整除
    char c[61];
    scanf("%s",c);
    int len=(int)strlen(c),n[len],sum=0;
    for(int i=len-1,j=0;i>=0;i--,j++){
        n[j]=c[i]-'0';
        sum+=n[j];
    }
    if(sum%9!=0){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<len;i++) n[i]*=len+1;
    for(int i=0;i<len-1;i++) if(n[i]>9){
        n[i+1]+=n[i]/10;
        n[i]%=10;
        if(n[i]!=9){
            printf("0\n");
            return 0;
        }
    }
    if(n[len-1]!=9) printf("0\n");
    else printf("1\n");
    return 0;
}
