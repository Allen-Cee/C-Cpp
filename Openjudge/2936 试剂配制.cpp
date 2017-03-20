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

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,m=0;
    scanf("%d",&n);
    while(n-->0){
        int t;
        scanf("%d",&t);
        m|=(1<<(--t));
    }
    if(((m&1)&&(m>>1&1))||((m>>2&1)&&(m>>3&1))||((m>>4&1)&&!(m>>5&1))||(!(m>>4&1)&&(m>>5&1))||(!(m>>6&1)&&!(m>>7&1))) printf("0\n");
    else printf("1\n");
    return 0;
}
