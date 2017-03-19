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
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int a=2,b,c;
    for(;a<101;a++) for(b=a;b<101;b++) for(c=b+1;c<101;c++) if(a*a+b*b==c*c) printf("%d*%d + %d*%d = %d*%d\n",a,a,b,b,c,c);
    return 0;
}
