#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int block[52][52],check[52][52],room[2500],num=0;

void markRoom(int x,int y){
    int wall[4];
    if(check[x][y]==0){
        room[num]++;
        check[x][y]=1;
        for(int k=0;k<4;k++){
            wall[k]=block[x][y]%2;
            block[x][y]/=2;
        }
        if(wall[0]==0) markRoom(x,y-1);
        if(wall[1]==0) markRoom(x-1,y);
        if(wall[2]==0) markRoom(x,y+1);
        if(wall[3]==0) markRoom(x+1,y);
    }
}

int main() {
    int x,y,max=0;
    cin>>x>>y;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            cin>>block[i][j];
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if(check[i][j]==0){
                num++;
                markRoom(i,j);
            }
    for(int i=0;i<num;i++)
        if(max<room[i]) max=room[i];
    cout<<num<<endl<<max<<endl;
    return 0;
}
