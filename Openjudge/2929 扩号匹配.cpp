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
    int n;
    while(scanf("%d",&n)!=EOF){
        int l[n],ln=0;
        char num;
        getchar();
        for(int i=1;i<=n;i++){
            scanf("%c",&num);
            if(num=='1') l[ln++]=i;
            else printf("%d ",l[--ln]);
        }
        printf("\n");
    }
    return 0;
}
