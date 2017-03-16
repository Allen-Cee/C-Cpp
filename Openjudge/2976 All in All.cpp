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
    char s1[100001],s2[100001];
    while(scanf("%s%s",s1,s2)!=EOF){
        int i,j;
        for(i=0,j=0;s1[j]!='\0'&&s2[i]!='\0';i++) if(s1[j]==s2[i]) j++;
        if(s1[j]=='\0') printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}