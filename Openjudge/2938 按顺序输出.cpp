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
using namespace std;

int comp(const void *a,const void *b){
    return *(short *)b-*(short *)a;
}

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    short n[3];
    cin>>n[0]>>n[1]>>n[2];
    qsort(n,3,2,comp);
    cout<<n[0]<<" "<<n[1]<<" "<<n[2];
    return 0;
}
