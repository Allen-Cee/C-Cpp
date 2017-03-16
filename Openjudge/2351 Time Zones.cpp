//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char tn[31][5]={"GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
int tz[31][2]={{0,0},{1,0},{1,0},{0,0},{1,0},{1,0},{2,0},{2,0},{3,0},{3,0},{4,0},{-4,0},{-3,0},{-3,-30},{-2,-30},{-5,0},{-4,0},{-6,0},{-5,0},{-7,0},{-6,0},{-8,0},{-7,0},{-10,0},{-9,0},{-8,0},{10,0},{11,0},{9,30},{10,30},{8,0}};

int  main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n-->0){
        char time[10],time2[10],z1[5],z2[5],tmp[2],h=0,m;
        int tzn1=0,tzn2=0;
        bool b=0;
        scanf("%s",time);
        if(time[0]=='n'||time[0]=='m'){
            if(time[0]=='m') strcpy(time2,"a.m.");
            else strcpy(time2,"p.m.");
            b=1;
        }
        else scanf("%s",time2);
        scanf("%s%s",z1,z2);
        for(int i=0;i<31;i++){
            if(strcmp(z1,tn[i])==0) tzn1=i;
            if(strcmp(z2,tn[i])==0) tzn2=i;
        }
        tmp[0]=tz[tzn2][0]-tz[tzn1][0];
        tmp[1]=tz[tzn2][1]-tz[tzn1][1];
        if(b) m=tmp[1];
        else{
            h=atoi(strtok(time,":"));
            m=atoi(strtok(NULL,":"))+tmp[1];
        }
        if(h==12) h=0;
        if(time2[0]=='p') h+=12;
        h+=tmp[0];
        if(m>59){
            h++;
            m-=60;
        }
        if(m<0){
            h--;
            m+=60;
        }
        if(h<0) h+=24;
        h%=24;
        if(h>=12){
            h-=12;
            if(h==0) h+=12;
            if(h==12&&m==0) printf("noon\n");
            else printf("%d:%02d p.m.\n",h,m);
        }
        else{
            if(h==0) h+=12;
            if(h==12&&m==0) printf("midnight\n");
            else printf("%d:%02d a.m.\n",h,m);
        }
    }
    return 0;
}
