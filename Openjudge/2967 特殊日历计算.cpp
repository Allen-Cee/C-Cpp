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

#define SPHM 100
#define SPMS 100
#define SPHS 10000
#define SPMD 100
#define SPYD 1000

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    short md[13]={0,31,59,90,120,151,181,212,243,273,304,334,365},lmd[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
    scanf("%d",&n);
    while(n-->0){
        int ad=0,as=0,d=0,mon=0,y=0;
        float h=0,min=0,s=0;
        scanf("%f:%f:%f %d.%d.%d",&h,&min,&s,&d,&mon,&y);
        y-=2000;
        if((y%4==0&&y%100!=0)||y%400==0) ad=y*365+(y+3)/4-(y-1)/100+(y-1)/400+lmd[mon-1]+d-1;
        else ad=y*365+(y+3)/4-(y-1)/100+(y-1)/400+md[mon-1]+d-1;
        as=(int)((h*3600+min*60+s)*1000/864);
        //cout<<"as "<<as<<" int as "<<(int)as<<endl;
        printf("%d:%d:%d %d.%d.%d\n",as/SPHS,(as/SPMS)%SPHM,as%SPMS,ad%SPYD%SPMD+1,ad%SPYD/SPMD+1,ad/SPYD);
    }
    return 0;
}
