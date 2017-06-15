//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <memory.h>
using namespace std;

int segment[210][2];
int point[210][210][210];

int maxPoint(int left,int right,int rlen){
    
    if(left==right) return pow(segment[left][1]+rlen,2);
    if(left+1==right){
        if(segment[left][0]==segment[right][0]) return pow(segment[left][1]+segment[right][1]+rlen,2);
        else return pow(segment[left][1],2)+pow(segment[right][1]+rlen,2);
    }
    
    int maxMerge=0;
    if(point[left][right-1][0]==0) point[left][right-1][0]=maxPoint(left,right-1,0);
    int maxDemi=point[left][right-1][0]+pow(segment[right][1]+rlen,2);
    for(int i=left;i<right-1;++i){
        if(segment[i][0]==segment[right][0]){
            if(point[left][i][segment[right][1]+rlen]==0) point[left][i][segment[right][1]+rlen]=maxPoint(left,i,segment[right][1]+rlen);
            if(point[i+1][right-1][0]==0) point[i+1][right-1][0]=maxPoint(i+1,right-1,0);
            int tmpMerge=point[left][i][segment[right][1]+rlen]+point[i+1][right-1][0];
            if(maxMerge<tmpMerge){
                maxMerge=tmpMerge;
            }
        }
    }
    
    return max(maxDemi,maxMerge);
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int cases=0,no=0;
    scanf("%d",&cases);
    while(cases-->0){
        memset(point,0,sizeof(point));
        memset(segment,0,sizeof(segment));
        int n=0;
        scanf("%d",&n);
        int box[n];
        int snum=1;
        for(int i=0;i<n;i++){
            scanf("%d",&box[i]);
            if(i>0&&box[i]!=box[i-1]) ++snum;
            segment[snum-1][0]=box[i];
            ++segment[snum-1][1];
        }
        int p=maxPoint(0,snum-1,0);
        printf("Case %d: %d\n",++no,p);
    }
    return 0;
}
