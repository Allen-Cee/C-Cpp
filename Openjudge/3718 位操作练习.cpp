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
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases-->0){
        unsigned short a,b;
        bool bo=0;
        scanf("%hu%hu",&a,&b);
        if(a==b) bo=1;
        else for(int i=1;i<16;i++){
            a=((a>>15)&1)|(a<<1);
            //printf("%hu ",a);
            if(a==b){
                bo=1;
                break;
            }
        }
        if(bo) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
