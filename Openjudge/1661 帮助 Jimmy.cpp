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

int N,MIN,X,Y,MAX,LIMIT=1000000000;

class Terrace{
public:
    int left,right,hight,ltime=LIMIT,rtime=LIMIT;
};

Terrace terrace[1000];

bool toGround(int ci,int x,int y){
    if(y>MAX) return false;
    for(int i=ci+1;y-terrace[i].hight<=MAX&&i<N;i++)
        if(terrace[i].left<=x&&terrace[i].right>=x)
            return false;
    return true;
}

int jumpFrom(int ci,int x,int actime){
    //cout<<"Checking JF "<<ci<<endl;
    if(terrace[ci].ltime!=LIMIT||terrace[ci].rtime!=LIMIT) return (x-terrace[ci].left+terrace[ci].ltime<terrace[ci].right-x+terrace[ci].rtime)?(x-terrace[ci].left+terrace[ci].ltime):(terrace[ci].right-x+terrace[ci].rtime);
    bool lg=toGround(ci,terrace[ci].left,terrace[ci].hight),rg=toGround(ci,terrace[ci].right,terrace[ci].hight);
    if(lg&&rg)
        return ((x-terrace[ci].left+terrace[ci].hight)<(terrace[ci].right-x+terrace[ci].hight))?(x-terrace[ci].left+terrace[ci].hight):(terrace[ci].right-x+terrace[ci].hight);
    bool lm=true,rm=true;//left_mark right_mark
    if(lg){
        terrace[ci].ltime=terrace[ci].hight;
        lm=false;
    }
    if(rg){
        terrace[ci].rtime=terrace[ci].hight;
        rm=false;
    }
    for(int i=ci+1;terrace[ci].hight-terrace[i].hight<=MAX&&i<N;i++){
        if(lm&&terrace[i].left<=terrace[ci].left&&terrace[i].right>=terrace[ci].left){
            terrace[ci].ltime=terrace[ci].hight-terrace[i].hight+jumpFrom(i,terrace[ci].left,actime+x-terrace[ci].left);
            lm=false;
        }
        if(rm&&terrace[i].left<=terrace[ci].right&&terrace[i].right>=terrace[ci].right){
            terrace[ci].rtime=terrace[ci].hight-terrace[i].hight+jumpFrom(i,terrace[ci].right,actime+terrace[ci].right-x);
            rm=false;
        }
        if(!lm&&!rm) break;
    }
    //cout<<"jumpFrom "<<ci<<" "<<x<<" "<<terrace[ci].ltime<<" "<<terrace[ci].rtime<<endl;
    if(terrace[ci].ltime!=LIMIT||terrace[ci].rtime!=LIMIT) return (x-terrace[ci].left+terrace[ci].ltime<terrace[ci].right-x+terrace[ci].rtime)?(x-terrace[ci].left+terrace[ci].ltime):(terrace[ci].right-x+terrace[ci].rtime);
    else return LIMIT;
}

int comp(const void *a,const void *b){
    return (*(Terrace *)b).hight-(*(Terrace *)a).hight;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d%d%d",&N,&X,&Y,&MAX);
        for(int i=0;i<N;i++) scanf("%d%d%d",&terrace[i].left,&terrace[i].right,&terrace[i].hight);
        qsort(terrace,N,sizeof(terrace[0]),comp);
        if(toGround(-1,X,Y)) MIN=Y;
        else for(int i=0;Y-terrace[i].hight<=MAX&&i<N;i++){
            if(Y<terrace[i].hight) continue;
            if(terrace[i].left<=X&&terrace[i].right>=X){
                MIN=jumpFrom(i,X,0)+Y-terrace[i].hight;
                break;
            }
        }
        printf("%d\n",MIN);
        for(int i=0;i<N;i++){
            terrace[i].left=0;
            terrace[i].right=0;
            terrace[i].hight=0;
            terrace[i].ltime=LIMIT;
            terrace[i].rtime=LIMIT;
        }
    }
    return 0;
}
