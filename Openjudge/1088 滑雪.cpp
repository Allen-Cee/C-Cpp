#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int r,c;
int map[100][100];
int ex[100][100];

int check(int a,int b){
    if(ex[a][b]!=-1) return ex[a][b];
    int max=0;
    int test=0;
    if(a>0&&map[a-1][b]<map[a][b]){
        int up=check(a-1,b)+1;
        max=up;
        test=1;
    }
    if(b>0&&map[a][b-1]<map[a][b]){
        int left=check(a,b-1)+1;
        if(max<left) max=left;
        test=1;
    }
    if(a<r-1&&map[a+1][b]<map[a][b]){
        int down=check(a+1,b)+1;
        if(max<down) max=down;
        test=1;
    }
    if(b<c-1&&map[a][b+1]<map[a][b]){
        int right=check(a,b+1)+1;
        if(max<right) max=right;
        test=1;
    }
    if(test==1) ex[a][b]=max;
    else ex[a][b]=0;
    return ex[a][b];
}

int main() {
    int max=0;
    int route;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ex[i][j]=-1;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ex[i][j]!=-1) route=ex[i][j];
            else route=check(i,j)+1;
            if(max<route) max=route;
        }
    }
    cout<<max<<endl;
    return 0;
}