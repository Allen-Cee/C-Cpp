//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <memory.h>
using namespace std;

int n,board[10][10]={};
int score[10][10][10][10]={-1};
int minscore[10][10][10][10][20]={-1};

int minMatrix(int lui,int luj,int rdi,int rdj,int num){
    int sum=100000000;
    
    if(num==n){
        if(score[lui][luj][rdi][rdj]<0){
            score[lui][luj][rdi][rdj]=0;
            for(int i=lui;i<=rdi;++i){
                for(int j=luj;j<=rdj;++j){
                    score[lui][luj][rdi][rdj]+=board[i][j];
                }
            }
            score[lui][luj][rdi][rdj]*=score[lui][luj][rdi][rdj];
            minscore[lui][luj][rdi][rdj][n]=score[lui][luj][rdi][rdj];
        }
        return score[lui][luj][rdi][rdj];
    }
    
    //left
    for(int cj=luj;cj<=rdj-1;++cj){
        if(rdj-cj+rdi-lui+1<n-num) break;
        
        int cut=0,rem=0;
        
        if(score[lui][luj][rdi][cj]>-1) cut=score[lui][luj][rdi][cj];
        else{
            for(int i=lui;i<=rdi;++i){
                for(int j=luj;j<=cj;++j){
                    cut+=board[i][j];
                }
            }
            cut*=cut;
            score[lui][luj][rdi][cj]=cut;
            minscore[lui][luj][rdi][cj][n]=score[lui][luj][rdi][cj];
        }
        
        if(minscore[lui][cj+1][rdi][rdj][num+1]<0) minscore[lui][cj+1][rdi][rdj][num+1]=minMatrix(lui,cj+1,rdi,rdj,num+1);
        rem=minscore[lui][cj+1][rdi][rdj][num+1];
        if(sum>cut+rem){
            sum=cut+rem;
        }
    }
    
    //right
    for(int cj=luj+1;cj<=rdj;++cj){
        if(cj-luj+rdi-lui+1<n-num) continue;
        
        int cut=0,rem=0;
        
        if(score[lui][cj][rdi][rdj]>-1) cut=score[lui][cj][rdi][rdj];
        else{
            for(int i=lui;i<=rdi;++i){
                for(int j=cj;j<=rdj;++j){
                    cut+=board[i][j];
                }
            }
            cut*=cut;
            score[lui][cj][rdi][rdj]=cut;
            minscore[lui][cj][rdi][rdj][n]=score[lui][cj][rdi][rdj];
        }
        
        if(minscore[lui][luj][rdi][cj-1][num+1]<0) minscore[lui][luj][rdi][cj-1][num+1]=minMatrix(lui,luj,rdi,cj-1,num+1);
        rem=minscore[lui][luj][rdi][cj-1][num+1];
        
        if(sum>cut+rem){
            sum=cut+rem;
        }
    }
    
    //up
    for(int ci=lui;ci<=rdi-1;++ci){
        if(rdj-luj+1+rdi-ci<n-num) break;
        
        int cut=0,rem=0;
        
        if(score[lui][luj][ci][rdj]>-1) cut=score[lui][luj][ci][rdj];
        else{
            for(int i=lui;i<=ci;++i){
                for(int j=luj;j<=rdj;++j){
                    cut+=board[i][j];
                }
            }
            cut*=cut;
            score[lui][luj][ci][rdj]=cut;
            minscore[lui][luj][ci][rdj][n]=score[lui][luj][ci][rdj];
        }
        
        if(minscore[ci+1][luj][rdi][rdj][num+1]<0) minscore[ci+1][luj][rdi][rdj][num+1]=minMatrix(ci+1,luj,rdi,rdj,num+1);
        rem=minscore[ci+1][luj][rdi][rdj][num+1];
        
        if(sum>cut+rem){
            sum=cut+rem;
        }
    }
    
    //down
    for(int ci=lui+1;ci<=rdi;++ci){
        if(rdj-luj+1+ci-lui<n-num) continue;
        
        int cut=0,rem=0;
        
        if(score[ci][luj][rdi][rdj]>-1) cut=score[ci][luj][rdi][rdj];
        else{
            for(int i=ci;i<=rdi;++i){
                for(int j=luj;j<=rdj;++j){
                    cut+=board[i][j];
                }
            }
            cut*=cut;
            score[ci][luj][rdi][rdj]=cut;
            minscore[ci][luj][rdi][rdj][n]=score[ci][luj][rdi][rdj];
        }
        
        if(minscore[lui][luj][ci-1][rdj][num+1]<0) minscore[lui][luj][ci-1][rdj][num+1]=minMatrix(lui,luj,ci-1,rdj,num+1);
        rem=minscore[lui][luj][ci-1][rdj][num+1];
        
        if(sum>cut+rem){
            sum=cut+rem;
        }
    }
    return sum;
}

int main(){
    freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int sum=0,tol=0;
    for(int v1=0;v1<10;++v1){
        for(int v2=0;v2<10;++v2){
            for(int v3=0;v3<10;++v3){
                for(int v4=0;v4<10;++v4){
                    score[v1][v2][v3][v4]=-1;
                    for(int v5=0;v5<20;++v5) minscore[v1][v2][v3][v4][v5]=-10;
                }
            }
        }
    }
    scanf("%d",&n);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%d",&board[i][j]);
            tol+=board[i][j];
        }
    }
    sum=minMatrix(0,0,7,7,1);
    double sigma=sqrt(sum/(double)n-pow(tol/(double)n,2));
    printf("%.3f\n",sigma);
    return 0;
}
