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

class Mouse{
public:
    int w;
    char hat[11];
};

int comp(const void *a,const void *b){
    return (*(Mouse *)b).w-(*(Mouse *)a).w;
}

int main() {
    int n;
    scanf("%d",&n);
    Mouse m[n];
    for(int i=0;i<n;i++) scanf("%d%s",&m[i].w,m[i].hat);
    qsort(m,n,sizeof(m[0]),comp);
    for(int i=0;i<n;i++) printf("%s\n",m[i].hat);
    return 0;
}
