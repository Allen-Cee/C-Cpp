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
    char s[1000][21];
    int n=0;
    while(scanf("%s",s[n])!=EOF) n++;
    int m[1000]={};
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int c=0;s[i][c]!='\0'&&s[j][c]!='\0';c++){
                if(s[i][c]!=s[j][c]) break;
                if(c>=m[i]) m[i]++;
                if(c>=m[j]) m[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s ",s[i]);
        for(int j=0;j<=m[i]&&s[i][j]!='\0';j++) printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}
