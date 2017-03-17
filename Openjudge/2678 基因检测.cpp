//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    cin>>n;
    while(n-->0){
        int max=0,len;
        char s1[21],s2[21];
        scanf("%s%s",s1,s2);
        len=(int)strlen(s1);
        if(len>strlen(s2)) len=(int)strlen(s2);
        while(len>0){
            for(int i1=0;i1+len<=strlen(s1);i1++){
                for(int i2=0;i2+len<=strlen(s2);i2++){
                    if(memcmp(&s1[i1],&s2[i2],len)==0){
                        max=len;
                        goto Done;
                    }
                }
            }
            len--;
        }
    Done:
        printf("%d\n",max);
    }
    return 0;
}
