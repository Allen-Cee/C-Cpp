//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 6/9/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

int C[6][6];

int P(int color,int comb){
    int B[6][6];
    memcpy(B,C,sizeof(B));
    int num=0;
    for(int i=0;i<4;++i){
        if((comb>>i)&1){
            ++num;
            B[1][i+1]*=-1;
            B[1][i]*=-1;
            B[1][i+2]*=-1;
            B[0][i+1]*=-1;
            B[2][i+1]*=-1;
        }
    }
    for(int r=2;r<5;++r){
        for(int c=1;c<5;++c){
            if(B[r-1][c]==-1*color){
                ++num;
                B[r][c]*=-1;
                B[r][c+1]*=-1;
                B[r][c-1]*=-1;
                B[r+1][c]*=-1;
            }
        }
    }
    bool b=true;
    for(int c=1;c<5;++c){
        if(B[4][c]==-1*color){
            b=false;
            break;
        }
    }
    
    if(b) return num;
    else return 21;
}

int main(int argc, const char * argv[]) {
    for(int i=1;i<5;++i){
        for(int j=1;j<5;++j){
            char c;
            scanf("%c",&c);
            if(c=='w') C[i][j]=1;
            else C[i][j]=-1;
        }
        getchar();
    }
    
    int result=20;
    for(int comb=0;comb<16;++comb){
        int white=P(1,comb);
        int black=P(-1,comb);
        if(result>white) result=white;
        if(result>black) result=black;
    }
    
    if(result==20) printf("Impossible\n");
    else printf("%d\n",result);
    
    return 0;
}
