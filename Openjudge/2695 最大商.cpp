//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<memory.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,mi=0;
    scanf("%d",&n);
    float a[n],r,mr=0;
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
        if(i==1){
            mr=a[0]/a[1];
            mi=1;
        }
        if(i>1){
            r=a[i-1]/a[i];
            if(r>mr){
                mr=r;
                mi=i;
            }
        }
    }
    printf("%f / %f = %f\n",a[mi-1],a[mi],mr);
    return 0;
}
