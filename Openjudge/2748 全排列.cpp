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
    return *(short *)a-*(short *)b;
}

void arrange(short wn[],short length,short start){
    if(start==length-1){
        for(int i=0;i<length;i++) printf("%c",(char)(wn[i]+'a'));
        printf("\n");
    }
    else{
        short wn_bp[length-start];
        for(int i=start;i<length;i++) wn_bp[i]=wn[i];
        for(int i=start;i<length;i++){
            short tmp=wn[start];
            wn[start]=wn[i];
            wn[i]=tmp;
            qsort(wn+start+1,length-start-1,sizeof(short),comp);
            arrange(wn,length,start+1);
            for(int i=start;i<length;i++) wn[i]=wn_bp[i];
        }
    }
}

int main() {
    char w[7];
    scanf("%s",w);
    short len=(short)strlen(w),wn[len];
    for(int i=0;w[i]!='\0';i++) wn[i]=w[i]-'a';
    qsort(wn,len,sizeof(short),comp);
    arrange(wn,len,0);
    return 0;
}