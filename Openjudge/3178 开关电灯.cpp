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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=i;j++) if(i%j==0) tmp++;
        if(tmp%2==0) printf("%d ",i);
    }
    printf("\n");
    return 0;
}
