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

int n,k;
bool visited[200020];

class pos{
public:
    int x,s;
};

pos q[100010];

void BFS(int node,int child){
    //cout<<"CHECKING... NODE "<<node<<" WITH X "<<q[node].x<<" AND STEP "<<q[node].s<<endl;
    visited[q[node].x]=1;
    if(q[node].x*2<k+2&&(!visited[q[node].x*2])){
        child++;
        q[child].x=q[node].x*2;
        q[child].s=q[node].s+1;
        if(q[child].x==k){
            printf("%d\n",q[child].s);
            return;
        }
        visited[q[child].x]=1;
    }
    if(q[node].x+1<=k&&(!visited[q[node].x+1])){
        child++;
        q[child].x=q[node].x+1;
        q[child].s=q[node].s+1;
        if(q[child].x==k){
            printf("%d\n",q[child].s);
            return;
        }
        visited[q[child].x]=1;
    }
    if(q[node].x-1>=0&&(!visited[q[node].x-1])){
        child++;
        q[child].x=q[node].x-1;
        q[child].s=q[node].s+1;
        if(q[child].x==k){
            printf("%d\n",q[child].s);
            return;
        }
        visited[q[child].x]=1;
    }
    node++;
    BFS(node,child);
}

int main(){
    scanf("%d%d",&n,&k);
    if(n>=k) printf("%d\n",n-k);
    else{
        q[0].x=n;
        q[0].s=0;
        BFS(0,0);
    }
    return 0;
}
