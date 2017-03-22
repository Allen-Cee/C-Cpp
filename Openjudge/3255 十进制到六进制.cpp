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
    int n;
    scanf("%d",&n);
    while(n-->0){
        int num;
        char s[20];
        memset(s,'\0',sizeof(s));
        scanf("%d",&num);
        if(num==0){
            printf("0\n");
            continue;
        }
        for(int i=0;num>0;i++){
            s[i]=num%6+'0';
            num-=num%6;
            num/=6;
        }
        for(int i=(int)strlen(s)-1;i>=0;i--) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
