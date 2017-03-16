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
    while(scanf("%d",&n)){
        if(n==0) break;
        int c[n];
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        int loop[n];
        for(int i=0;i<n;i++){
            loop[i]=1;
            int to=i;
            while(c[to]!=i+1){
                to=c[to]-1;
                loop[i]++;
            }
            if(c[i]==i+1) loop[i]=0;
        }
        int k;
        while(scanf("%d",&k)){
            if(k==0) break;
            char s[n+1],p[n],t[n];
            memset(p,' ',n);
            memset(t,' ',n);
            getchar();
            gets(s);
            for(int i=0;s[i]!='\0';i++) p[i]=s[i];
            for(int i=0;i<n;i++){
                int num=0,to=i;
                if(loop[i]>0) num=k%loop[i];
                while(num-->0) to=c[to]-1;
                t[to]=p[i];
            }
            for(int i=0;i<n;i++) printf("%c",t[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}