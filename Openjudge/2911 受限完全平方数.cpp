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

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int max;
    scanf("%d",&max);
    for(int a=45;a*a<max;a++) for(int b=32;b<sqrt(a*a-1000);b++) if((a*a-b*b)/1000==(a*a-b*b)/100%10&&(a*a-b*b)/100%10==(a*a-b*b)/10%10&&(a*a-b*b)/10%10==(a*a-b*b)%10) printf("%d\n",a*a);
    return 0;
}
