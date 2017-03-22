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

#define ERROR 0.000001

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    double n,a;
    while(scanf("%lf",&n)!=EOF){
        int num=1;
        a=1;
        while(abs(a*a-n)>ERROR){
            //cout<<a<<endl;
            a=a-(a*a-n)/(2*a);
            num++;
        }
        printf("%d %.2lf\n",num,a);
    }
    return 0;
}
