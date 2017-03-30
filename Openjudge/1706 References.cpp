//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

class Reference{
public:
    int ln=0,index;
    char l[3][81];
};

Reference r[1000];

bool CBL(char *line){
    bool b=1;
    for(int i=0;line[i]!='\0';i++) if(line[i]!=' '&&line[i]!='\n'){
        b=0;
        break;
    }
    return b;
}

void SR(char *line){
    //处理第一行
    char fn[4];
    memset(fn,'\0',sizeof(fn));
    for(int i=1;line[i]!=']';i++) fn[i-1]=line[i];
    int in=atoi(fn);
    strcpy(r[in].l[0],line);
    r[in].ln++;
    memset(line,'\0',81);
    //处理剩余行
    while(gets(line)){
        if(CBL(line)) return;
        int tmp_ln=r[in].ln;
        strcpy(r[in].l[tmp_ln],line);
        r[in].ln++;
        memset(line,'\0',81);
    }
}

void HP(char *line,int &rn,int *rb){
    //处理第一行
    char fn[4];
    int in;
    memset(fn,'\0',sizeof(fn));
    for(int i=0;line[i]!='\0';i++){
        printf("%c",line[i]);
        if(line[i]=='['){
            int tmp_i=0;
            i++;
            while(line[i]!=']') fn[tmp_i++]=line[i++];
            in=atoi(fn);
            int rbn=0;
            for(int j=1;j<rn;j++){
                if(rb[j]==in){
                    rbn=j;
                    break;
                }
            }
            if(rbn) printf("%d",rbn);
            else{
                printf("%d",rn);
                rb[rn++]=in;
            }
            memset(fn,'\0',sizeof(fn));
            printf("%c",line[i]);
        }
    }
    printf("\n");
    memset(line,'\0',81);
    //处理剩余行
    while(gets(line)){
        if(CBL(line)){
            printf("\n");
            return;
        }
        for(int i=0;line[i]!='\0';i++){
            printf("%c",line[i]);
            if(line[i]=='['){
                int tmp_i=0;
                i++;
                while(line[i]!=']') fn[tmp_i++]=line[i++];
                in=atoi(fn);
                int rbn=0;
                for(int j=1;j<rn;j++){
                    if(rb[j]==in){
                        rbn=j;
                        break;
                    }
                }
                if(rbn) printf("%d",rbn);
                else{
                    printf("%d",rn);
                    rb[rn++]=in;
                }
                memset(fn,'\0',sizeof(fn));
                printf("%c",line[i]);
            }
        }
        printf("\n");
        memset(line,'\0',81);
    }
    printf("\n");
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    char line[81];
    int rn=1,rb[1000];
    memset(line,'\0',sizeof(line));
    while(gets(line)){
        //遇到空行跳过
        if(CBL(line)) continue;
        //遇到reference按照其原始index储存为Reference对象
        if(line[0]=='[') SR(line);
        //遇到paragraph遍历输出至空白行 中间判断reference原始下标出现并按先后存至reference book
        else HP(line,rn,rb);
        memset(line,'\0',sizeof(line));
    }
    for(int i=1;i<rn;i++){
        int tmp_ln=r[rb[i]].ln;
        for(int j=0;j<tmp_ln;j++){
            if(j==0){
                printf("[%d]",i);
                int tmp_i=0;
                while(r[rb[i]].l[j][tmp_i++]!=']');
                while(r[rb[i]].l[j][tmp_i]!='\0') printf("%c",r[rb[i]].l[j][tmp_i++]);
                printf("\n");
            }
            else printf("%s\n",r[rb[i]].l[j]);
        }
        printf("\n");
    }
    return 0;
}
