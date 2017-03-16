#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int map[102][102],mark[102][102],n,way,ox,oy;

void check(int x,int y,int lx,int ly){
    //cout<<"Checking("<<x<<","<<y<<")..."<<endl;
    mark[x][y]=1;
    if(map[x][y]==0) return;
    if(x==ox&&y==oy){
        way=1;
        return;
    }
    else{
        if(mark[x][y+1]==0&&way==0) check(x,y+1,x,y);
        if(mark[x+1][y]==0&&way==0) check(x+1,y,x,y);
        if(mark[x][y-1]==0&&way==0) check(x,y-1,x,y);
        if(mark[x-1][y]==0&&way==0) check(x-1,y,x,y);
        
    }
}

int main() {
    int k;
    cin>>k;
    for(int i=0;i<102;i++)
        for(int j=0;j<102;j++){
            map[i][j]=-1;
            mark[i][j]=-1;
        }
    while(k-->0){
        way=0;
        ox=0;
        oy=0;
        int ix,iy;
        char pot;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>pot;
                mark[i][j]=0;
                if(pot=='.') map[i][j]=1;
                else if(pot=='#') map[i][j]=0;
            }
        }
        cin>>ix>>iy>>ox>>oy;
        ix++;
        iy++;
        ox++;
        oy++;
        check(ix,iy,0,0);
        if(way==1) cout<<"YES"<<endl;
        else if(way==0) cout<<"NO"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map[i][j]=-1;
                mark[i][j]=-1;
            }
        }
    }
    return 0;
}