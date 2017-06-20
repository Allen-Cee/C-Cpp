//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 6/9/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <memory.h>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n=0,l=0;
    int a=0,b=0;
    scanf("%d%d%d%d",&n,&l,&a,&b);
    bool p[l+10];
    int f[l+10];
    multiset<int> m;
    multiset<int>::iterator mi;
    
    bool un=0;
    if(l<2*a) un=1;
    
    memset(p,0,sizeof(p));
    for(int i=0;i<n;++i){
        int tmpl=0,tmpr=0;
        scanf("%d%d",&tmpl,&tmpr);
        if(tmpr-tmpl>2*b) un=1;
        for(int j=tmpl+1;j<tmpr;++j) p[j]=1;
    }
    
    
    memset(f,0,sizeof(f));
    
    for(int curp=2*a;curp<=2*b&&curp<=l;curp+=2){
        if(p[curp]) continue;
        f[curp]=1;
    }
    
    for(int curp=4*a;curp<=l;curp+=2){
        mi=m.find(f[curp-2*b-2]);
        if(curp>2*b+2&&f[curp-2*b-2]&&mi!=m.end()) m.erase(mi);
        if(f[curp-2*a]) m.insert(f[curp-2*a]);
        if(p[curp]) continue;
        
        if(curp>2*b&&!m.empty()){
            f[curp]=*(m.begin())+1;
        }
    }
    
    if(un||!f[l]) printf("-1\n");
    else printf("%d\n",f[l]);
    return 0;
}
