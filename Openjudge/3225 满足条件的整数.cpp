//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    for(int a=2;a<=100;a++) for(int b=a;b<=100;b++){
        int c=(int)sqrt(a*a+b*b);
        if(a*a+b*b==c*c&&c<=100) printf("%d*%d + %d*%d = %d*%d\n",a,a,b,b,c,c);
    }
    return 0;
}
