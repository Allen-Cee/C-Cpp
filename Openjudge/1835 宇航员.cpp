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
    freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases-->0){
        int n,p[6]={0,0,0,0,0,0},o[2]={0,2};//o[2] indicate the body orientation and head orientation
        scanf("%d",&n);
        while(n-->0){
            char ori[10];
            int num;
            scanf("%s%d",ori,&num);
            if(ori[0]=='f') p[o[0]]+=num;
            else if(ori[0]=='b'){
                o[0]=(o[0]+3)%6;
                p[o[0]]+=num;
            }
            else if(ori[0]=='l'){
                if(o[1]==2){
                    if(o[0]==0) o[0]=4;
                    else if(o[0]==4) o[0]=3;
                    else if(o[0]==3) o[0]=1;
                    else if(o[0]==1) o[0]=0;
                }
                else if(o[1]==5){
                    if(o[0]==0) o[0]=1;
                    else if(o[0]==1) o[0]=3;
                    else if(o[0]==3) o[0]=4;
                    else if(o[0]==4) o[0]=0;
                }
                else if(o[1]==0){
                    if(o[0]==2) o[0]=1;
                    else if(o[0]==1) o[0]=5;
                    else if(o[0]==5) o[0]=4;
                    else if(o[0]==4) o[0]=2;
                }
                else if(o[1]==3){
                    if(o[0]==2) o[0]=4;
                    else if(o[0]==4) o[0]=5;
                    else if(o[0]==5) o[0]=1;
                    else if(o[0]==1) o[0]=2;
                }
                else if(o[1]==1){
                    if(o[0]==2) o[0]=3;
                    else if(o[0]==3) o[0]=5;
                    else if(o[0]==5) o[0]=0;
                    else if(o[0]==0) o[0]=2;
                }
                else if(o[1]==4){
                    if(o[0]==2) o[0]=0;
                    else if(o[0]==0) o[0]=5;
                    else if(o[0]==5) o[0]=3;
                    else if(o[0]==3) o[0]=2;
                }
                p[o[0]]+=num;
            }
            else if(ori[0]=='r'){
                if(o[1]==2){
                    if(o[0]==0) o[0]=1;
                    else if(o[0]==1) o[0]=3;
                    else if(o[0]==3) o[0]=4;
                    else if(o[0]==4) o[0]=0;
                }
                else if(o[1]==5){
                    if(o[0]==0) o[0]=4;
                    else if(o[0]==4) o[0]=3;
                    else if(o[0]==3) o[0]=1;
                    else if(o[0]==1) o[0]=0;
                }
                else if(o[1]==0){
                    if(o[0]==2) o[0]=4;
                    else if(o[0]==4) o[0]=5;
                    else if(o[0]==5) o[0]=1;
                    else if(o[0]==1) o[0]=2;
                }
                else if(o[1]==3){
                    if(o[0]==2) o[0]=1;
                    else if(o[0]==1) o[0]=5;
                    else if(o[0]==5) o[0]=4;
                    else if(o[0]==4) o[0]=2;
                }
                else if(o[1]==1){
                    if(o[0]==2) o[0]=0;
                    else if(o[0]==0) o[0]=5;
                    else if(o[0]==5) o[0]=3;
                    else if(o[0]==3) o[0]=2;
                }
                else if(o[1]==4){
                    if(o[0]==2) o[0]=3;
                    else if(o[0]==3) o[0]=5;
                    else if(o[0]==5) o[0]=0;
                    else if(o[0]==0) o[0]=2;
                }
                p[o[0]]+=num;
            }
            else if(ori[0]=='u'){
                int tmp=o[0];
                o[0]=o[1];
                o[1]=(tmp+3)%6;
                p[o[0]]+=num;
            }
            else if(ori[0]=='d'){
                int tmp=o[1];
                o[1]=o[0];
                o[0]=(tmp+3)%6;
                p[o[0]]+=num;
            }
        }
        for(int i=0;i<3;i++) p[i]-=p[i+3];
        printf("%d %d %d %d\n",p[0],p[1],p[2],o[0]);
    }
    return 0;
}
