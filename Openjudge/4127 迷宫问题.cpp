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
#include <deque>
#include <memory.h>
using namespace std;

int M[7][7];
bool V[7][7];

class Father{
public:
    int lx=0,ly=0;
};

class Dot{
public:
    int x=0,y=0;
    Dot(int n1=0,int n2=0){
        y=n1;
        x=n2;
    }
};

int main(int argc, const char * argv[]) {
    freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    for(int i=1;i<6;++i){
        for(int j=1;j<6;++j){
            int n;
            scanf("%d",&n);
            if(n) M[i][j]=0;
            else M[i][j]=1;
        }
    }
    
    Father df[7][7];
    deque<Dot> dqrout;
    deque<Dot> dqans;
    dqrout.push_back(Dot(1,1));
    V[1][1]=1;
    int s=0;
    for(deque<Dot>::iterator i=dqrout.begin();i!=dqrout.end();++i){
        ++s;
        int curx=(*i).x;
        int cury=(*i).y;
        if(M[cury][curx+1]&&V[cury][curx+1]==0){
            df[cury][curx+1].ly=cury;
            df[cury][curx+1].lx=curx;
            dqrout.push_back(Dot(cury,curx+1));
            V[cury][curx+1]=1;
            if(cury==5&&curx==4) break;
        }
        if(M[cury+1][curx]&&V[cury+1][curx]==0){
            df[cury+1][curx].ly=cury;
            df[cury+1][curx].lx=curx;
            dqrout.push_back(Dot(cury+1,curx));
            V[cury+1][curx]=1;
            if(cury==4&&curx==5) break;
        }
        if(M[cury][curx-1]&&V[cury][curx-1]==0){
            df[cury][curx-1].ly=cury;
            df[cury][curx-1].lx=curx;
            dqrout.push_back(Dot(cury,curx-1));
            V[cury][curx-1]=1;
        }
        if(M[cury-1][curx]&&V[cury-1][curx]==0){
            df[cury-1][curx].ly=cury;
            df[cury-1][curx].lx=curx;
            dqrout.push_back(Dot(cury-1,curx));
            V[cury-1][curx]=1;
        }
    }
    int cury=5,curx=5;
    while(!(cury==1&&curx==1)){
        dqans.push_front(Dot(cury,curx));
        int tmpy=df[cury][curx].ly;
        int tmpx=df[cury][curx].lx;
        cury=tmpy;
        curx=tmpx;
    }
    dqans.push_front(Dot(1,1));
    for(deque<Dot>::iterator i=dqans.begin();i!=dqans.end();++i) printf("(%d, %d)\n",(*i).y-1,(*i).x-1);
    return 0;
}
