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
    int k,n;
    scanf("%d%d",&k,&n);
    while(n-->0){
        char s[10];
        int num;
        scanf("%s%d",s,&num);
        if(s[1]=='l') k+=num;
        else if(s[1]=='i') k-=num;
        else if(s[1]=='u') k*=num;
    }
    printf("%d\n",k);
    return 0;
}
