#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<unistd.h>
using namespace std;

int h,w,num;

void checkTile(int y,int x,char tile[21][21],int m[21][21]){
    if(m[y][x]==0){
        num++;
        m[y][x]=1;
        if(x>0&&tile[y][x-1]=='.') checkTile(y,x-1,tile,m);
        if(x<w-1&&tile[y][x+1]=='.') checkTile(y,x+1,tile,m);
        if(y>0&&tile[y-1][x]=='.') checkTile(y-1,x,tile,m);
        if(y<h-1&&tile[y+1][x]=='.') checkTile(y+1,x,tile,m);
    }
}

int main() {
    while(cin>>w>>h){
        if(w==0&&h==0) break;
        int sh=0,sw=0,m[21][21]={};
        num=0;
        char tile[21][21]={};
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                cin>>tile[i][j];
                if(tile[i][j]=='@'){
                    sh=i;
                    sw=j;
                }
            }
        checkTile(sh,sw,tile,m);
        cout<<num<<endl;
    }
    return 0;
}