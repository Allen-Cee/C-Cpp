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
    scanf("%d",&n);
    char in;
    int b[n+1][n+1],bc[n+1][n+1],min=n*n+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>in;
            if(in=='w') b[i][j]=1;
            else if(in=='y') b[i][j]=-1;
        }
    }
    for(int i=0;i<pow(2,n);i++){
        int sum=0;
        bool wa=false;
        for(int j=0;j<n;j++) for(int k=0;k<n;k++) bc[j][k]=b[j][k];
        for(int p=0;p<n;p++){
            if((i>>p)&1){
                bc[0][p]*=-1;
                if(p>0) bc[0][p-1]*=-1;
                if(p<n-1) bc[0][p+1]*=-1;
                if(n>1) bc[1][p]*=-1;
                sum++;
            }
        }
        for(int r=1;r<n;r++){
            for(int p=0;p<n;p++){
                if(bc[r-1][p]==1){
                    bc[r][p]*=-1;
                    if(p>0) bc[r][p-1]*=-1;
                    if(p<n-1) bc[r][p+1]*=-1;
                    if(r<n-1) bc[r+1][p]*=-1;
                    sum++;
                }
            }
        }
        for(int p=0;p<n;p++) if(bc[n-1][p]==1){
            wa=true;
            break;
        }
        if(wa) continue;
        if(min>sum) min=sum;
    }
    if(min==n*n+1) printf("inf\n");
    else printf("%d\n",min);
    return 0;
}
