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
    unsigned int d;
    while(scanf("%u",&d)){
        if(d==0) break;
        unsigned int dc=1,c=0,i=1;
        while(dc<=d){
            c+=i*i;
            i++;
            dc+=i;
        }
        dc-=i;
        c+=(d-dc)*i;
        printf("%u %u\n",d,c);
    }
    return 0;
}
