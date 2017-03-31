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

class Pot{
public:
    int x,y;
};

Pot p[100];

int CMP(const void *a,const void *b){
    return p[*(int *)a].x-p[*(int *)b].x;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n,num=0;
    scanf("%d",&n);
    int mp[n];
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=0;i<n;i++){
        bool b=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(p[i].x<=p[j].x&&p[i].y<=p[j].y){
                b=0;
                break;
            }
        }
        if(b) mp[num++]=i;
    }
    qsort(mp,num,sizeof(mp[0]),CMP);
    for(int i=0;i<num-1;i++) printf("(%d,%d),",p[mp[i]].x,p[mp[i]].y);
    printf("(%d,%d)\n",p[mp[num-1]].x,p[mp[num-1]].y);
    return 0;
}
