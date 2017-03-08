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
    int n,l,add=0;
    scanf("%d%d",&n,&l);
    int w[n];
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        add+=w[i];
    }
    int right=add/l,left=1;
    if(add==0||right==0){
        printf("0\n");
        return 0;
    }
    while(right>=left){
        int num=0,t=(left+right)/2;
        for(int i=0;i<n;i++){
            int one=1;
            while(one*t<=w[i]) one++;
            num+=one-1;
        }
        if(left==right){
            if(num>=l){
                if(right==0) printf("0\n");
                else printf("%d\n",t);
            }
            else printf("0\n");
            break;
        }
        if(num>l) left=t+1;
        else if(num<l) right=t-1;
        else{
            if(right-left>1){
                left=t;
                continue;
            }
            else{
                num=0;
                for(int i=0;i<n;i++){
                    int one=1;
                    while(one*(t+1)<=w[i]) one++;
                    num+=one-1;
                }
                if(num==l) left=t+1;
                else{
                    if(right==0) printf("0\n");
                    else printf("%d\n",t);
                    break;
                }
            }
        }
    }
    return 0;
}