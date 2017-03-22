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
    double h;
    cin>>h;
    double sum=h,i=0;
    for(;i<9;i++) sum+=pow(0.5,i)*h;
    cout<<sum<<endl<<pow(0.5,10)*h<<endl;
    return 0;
}
