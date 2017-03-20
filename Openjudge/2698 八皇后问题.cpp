//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int no;

void print(int board[8][8]){
    no++;
    printf("No. %d\n",no);
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++) printf("%d ",board[y][x]);
        printf("\n");
    }
}

void check(int board[8][8],int m[8],int cal){
    for(int i=0;i<8;i++){
        if(m[i]) continue;
        bool b=0;
        for(int n=1;cal-n>=0&&i-n>=0;n++) if(board[i-n][cal-n]){
            b=1;
            break;
        }
        if(b==0) for(int n=1;cal+n<8&&i+n<8;n++) if(board[i+n][cal+n]){
            b=1;
            break;
        }
        if(b==0) for(int n=1;cal-n>=0&&i+n<8;n++) if(board[i+n][cal-n]){
            b=1;
            break;
        }
        if(b==0) for(int n=1;cal+n<8&&i-n>=0;n++) if(board[i-n][cal+n]){
            b=1;
            break;
        }
        if(b) continue;
        m[i]=1;
        board[i][cal]=1;
        if(cal==7) print(board);
        else check(board,m,cal+1);
        m[i]=0;
        board[i][cal]=0;
    }
}

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int board[8][8],m[8],cal=0;
    memset(board,0,sizeof(board));
    memset(m,0,sizeof(m));
    check(board,m,cal);
    return 0;
}
