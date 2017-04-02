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
    int t;
    scanf("%d",&t);
    while(t-->0){
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        double delta=b*b-4*a*c,real=(b*-1)/(2*a);
        if(fabs(real)<1e-8) real=0;
        if(delta>0){
            double imag=fabs(sqrt(delta)/(2*a));
            printf("x1=%.5lf;x2=%.5lf\n",real+imag,real-imag);
        }
        else if(fabs(delta)<1e-8) printf("x1=x2=%.5lf\n",real);
        else{
            double imag=fabs((sqrt(-1*delta))/(2*a));
            printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",real,imag,real,imag);
        }
    }
    return 0;
}
