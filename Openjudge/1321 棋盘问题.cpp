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

int n,k,num,cb[8][8],cm[8];

void checkBoard(int r,int e,int p){//r所处行数 e位运算方案 p已放棋子
    if(((e>>r)&1)&&r<n){
        for(int i=0;i<n;i++){
            if(cb[r][i]==1){
                bool rp=false;//是否同列
                for(int j=0;j<r;j++){
                    if((e>>j)&1) if(cm[j]==i) rp=true;
                }
                if(rp) continue;
                cm[r]=i;
                if(p+1==k){
                    num++;//可选方案数
                    continue;
                }
                checkBoard(r+1,e,p+1);
            }
        }
    }
    else if(r<n-1) checkBoard(r+1,e,p);
}

int main() {
    while(scanf("%d%d",&n,&k)){
        if(n==-1&&k==-1) break;
        num=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++) cb[i][j]=0;
            cm[i]=-1;
        }
        char c;
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&c);
                if(c=='#') cb[i][j]=1;
            }
            getchar();
        }
        for(int i=0;i<pow(2,n);i++){
            int sum=0;
            for(int j=0;j<n;j++) if((i>>j)&1) sum++;
            if(sum==k) checkBoard(0,i,0);
        }
        printf("%d\n",num);
    }
    return 0;
}