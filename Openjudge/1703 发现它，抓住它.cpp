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

int F(int x,int *c,bool *r){
    if(c[x]!=x){
        //先取出tmp_f 因为其r[tmp_f]可能更新
        int tmp_f=c[x];
        c[x]=F(c[x],c,r);
        r[x]^=r[tmp_f];
        return c[x];
    }
    return x;
}

void MG(int a,int b,int *c,bool *r){
    int fa=F(a,c,r);
    int fb=F(b,c,r);
    c[fb]=fa;
    if(r[a]) r[fb]=r[b];
    else r[fb]=r[b]^1;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t-->0){
        int n,m;
        scanf("%d%d",&n,&m);
        int c[n+1];
        bool r[n+1];
        for(int i=0;i<n+1;i++){
            c[i]=i;
            r[i]=0;
        }
        while(m-->0){
            char ch;
            int a,b;
            getchar();
            scanf("%c%d%d",&ch,&a,&b);
            if(ch=='A'){
                if(n<=1) printf("Not sure yet.\n");
                else if(n==2){
                    if(a!=b) printf("In different gangs.\n");
                    else if(a==b) printf("In the same gang.\n");
                    continue;
                }
                else if(F(a,c,r)==F(b,c,r)){
                    if(r[a]==r[b]) printf("In the same gang.\n");
                    else printf("In different gangs.\n");
                }
                else printf("Not sure yet.\n");
            }
            else if(ch=='D') MG(a,b,c,r);
        }
    }
    return 0;
}

/*
 for(int i=1;i<=n;i++) cout<<c[i]<<" ";
 cout<<endl;
 for(int i=1;i<=n;i++) cout<<r[i]<<" ";
 cout<<endl;
 */
