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

class Dir{
public:
    char file[31][31];
    int fn=0,indent=0;
};

Dir dir[30];
int dn,be;
bool cont=true;

int comp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}

void getInput(int ind,int set){
    dn++;
    int num=dn;
    dir[num].fn=0;
    char input[31];
    while(scanf("%s",input)){
        //cout<<input[0]<<" ";
        if(input[0]=='f'){
            for(int i=0;input[i]!='\0';i++) dir[num].file[dir[num].fn][i]=input[i];
            dir[num].fn++;
        }
        if(input[0]=='d'){
            for(int i=0;i<ind;i++) printf("|     ");
            printf("%s\n",input);
            getInput(ind+1,set);
        }
        if(input[0]==']') break;
        if(input[0]=='*') break;
        if(input[0]=='#'){
            cont=0;
            return;
        }
        if(be==0){
            if(set>1) printf("\n");
            printf("DATA SET %d:\nROOT\n",set);
            be=1;
        }
        memset(input,'\0',31);
    }
    //cout<<ind<<" "<<dir[num].fn<<" "<<num<<endl;
    //cout<<dir[num].file[0]<<endl;
    if(dir[num].fn>0){
        qsort(dir[num].file,dir[num].fn,sizeof(dir[num].file[0]),comp);
        for(int i=0;i<dir[num].fn;i++){
            for(int j=0;j<ind-1;j++) printf("|     ");
            printf("%s\n",dir[num].file[i]);
        }
    }
}

int main() {
    int set=0;
    while(cont){
        be=0;
        dn=-1;
        getInput(1,++set);
        for(int i=0;i<31;i++) memset(dir[i].file,'\0',sizeof(dir[i].file[0]));
    }
    return 0;
}