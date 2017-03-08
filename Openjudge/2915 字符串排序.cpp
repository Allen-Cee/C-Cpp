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

int comp(const void *a,const void *b){
    return (int)strlen(*(char **)a)-(int)strlen(*(char **)b);
}

int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        char **s;
        s=new char*[n];
        for(int i=0;i<n;i++) s[i]=new char[200];
        int num;
        getchar();
        for(num=0;num<n;num++){
            gets(s[num]);
            if(strcmp(s[num],"stop")==0) break;
        }
        if(num>1) qsort(s,num,sizeof(s[0]),comp);
        for(int i=0;i<num;i++) printf("%s\n",s[i]);
        for(int i=0;i<n;i++) delete s[i];
        delete s;
    }
    return 0;
}