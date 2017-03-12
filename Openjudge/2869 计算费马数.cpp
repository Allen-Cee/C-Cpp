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
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int k,f=1;
    cin>>k;
    for(int i=0;i<k;i++) cout<<((f<<(1<<i))+1)<<endl;
    return 0;
}
