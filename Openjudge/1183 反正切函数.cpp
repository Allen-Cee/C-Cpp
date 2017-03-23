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
    long long a;
    scanf("%lld",&a);
    long long b=(long)(sqrt(a*a+1)+a),bmx=b,bmi=b;
    while((bmx*bmx+1)%(bmx-a)) bmx++;
    long long tmx=(bmx*bmx+1)/(bmx-a);
    while((bmi*bmi+1)%(bmi-a)&&((bmi*bmi+1)/(bmi-a))<tmx) bmi--;
    long long tmi=(bmi*bmi+1)/(bmi-a);
    if(tmx>=tmi&&(bmi*bmi+1)%(bmi-a)) printf("%lld\n",tmx);
    else printf("%lld\n",tmi);
    return 0;
}
