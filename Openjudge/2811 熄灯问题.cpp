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

int main() {
    int n;
    int b[5][6],bc[5][6],br[5][6];
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&n);
            if(n==1) b[i][j]=1;
            else if(n==0) b[i][j]=-1;
        }
    }
    for(int i=0;i<pow(2,6);i++){
        bool wa=false;
        for(int j=0;j<5;j++) for(int k=0;k<6;k++) bc[j][k]=b[j][k];
        memset(br,0,sizeof(br));
        for(int p=0;p<6;p++){
            if((i>>p)&1){
                bc[0][p]*=-1;
                if(p>0) bc[0][p-1]*=-1;
                if(p<5) bc[0][p+1]*=-1;
                bc[1][p]*=-1;
                br[0][p]=1;
            }
        }
        for(int r=1;r<5;r++){
            for(int p=0;p<6;p++){
                if(bc[r-1][p]==1){
                    bc[r][p]*=-1;
                    if(p>0) bc[r][p-1]*=-1;
                    if(p<5) bc[r][p+1]*=-1;
                    if(r<4) bc[r+1][p]*=-1;
                    br[r][p]=1;
                }
            }
        }
        for(int p=0;p<6;p++) if(bc[4][p]==1){
            wa=true;
            break;
        }
        if(wa) continue;
        for(int j=0;j<5;j++){
            int k;
            for(k=0;k<5;k++){
                printf("%d ",br[j][k]);
            }
            printf("%d\n",br[j][k]);
        }
    }
    return 0;
}