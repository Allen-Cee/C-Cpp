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
    int t;
    scanf("%d",&t);
    while(t-->0){
        int n,min=0,minlen;
        scanf("%d",&n);
        if(n==0) minlen=0;
        else minlen=200;
        char s[n][200];
        memset(s,'\0',sizeof(s));
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            if(minlen>strlen(s[i])){
                minlen=(int)strlen(s[i]);
                min=i;
            }
        }
        int len=minlen;
        for(len=minlen;len>0;len--){
            for(int i=0;i<=minlen-len;i++){
                int j=0;
                for(j=0;j<n;j++){
                    if(j==min) continue;
                    bool sub=false;
                    for(int k=0;k<=strlen(s[j])-len;k++){
                        int l=k;
                        for(l=k;l<k+len;l++){
                            if(s[min][l-k+i]!=s[j][l]) break;
                        }
                        if(l==k+len){
                            sub=true;
                            break;
                        }
                        for(l=k;l<k+len;l++){
                            if(s[min][i+len-1-(l-k)]!=s[j][l]) break;
                        }
                        if(l==k+len){
                            sub=true;
                            break;
                        }
                    }
                    if(sub==false) break;
                }
                if(j==n) goto Done;
            }
        }
    Done:
        printf("%d\n",len);
    }
    return 0;
}