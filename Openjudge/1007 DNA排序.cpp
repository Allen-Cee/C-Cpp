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

class DNA{
public:
    char con[51];
    int num=0;
};

int comp(const void *a,const void *b){
    return (*(DNA *)a).num-(*(DNA *)b).num;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    DNA dna[100];
    for(int t=0;t<m;t++){
        scanf("%s",dna[t].con);
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(dna[t].con[i]>dna[t].con[j]) dna[t].num++;
    }
    qsort(dna,m,sizeof(dna[0]),comp);
    for(int i=0;i<m;i++) printf("%s\n",dna[i].con);
    return 0;
}