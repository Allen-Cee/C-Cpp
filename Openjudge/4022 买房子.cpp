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
    int n,k;
    double p=200;
    bool b=1;
    scanf("%d%d",&n,&k);
    if(n>=p) printf("1\n");
    else for(int i=2;i<=20;i++){
        p*=(k/(double)100+1);
        if(i*n>=p){
            printf("%d\n",i);
            b=0;
            break;
        }
    }
    if(b) printf("Impossible\n");
    return 0;
}
