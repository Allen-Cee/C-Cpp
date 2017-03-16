#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int m[9][9]={{1,1,0,1,1,0,0,0,0},{1,1,1,0,0,0,0,0,0},{0,1,1,0,1,1,0,0,0},{1,0,0,1,0,0,1,0,0},{0,1,0,1,1,1,0,1,0},{0,0,1,0,0,1,0,0,1},{0,0,0,1,1,0,1,1,0},{0,0,0,0,0,0,1,1,1},{0,0,0,0,1,1,0,1,1}},mv[9],r[9],mx=0;

void printMoves(){
    for(int i=0;i<9;i++) for(int j=0;j<r[i];j++) cout<<i+1<<" ";
    cout<<endl;
}

int checkClock(int c[9]){
    int t=0;
    for(int i=0;i<9;i++){
        while(c[i]<0) c[i]+=4;
        while(c[i]>4) c[i]%=4;
    }
    for(int i=0;i<9&&t==0;i++) if(c[i]!=0) t=1;
    return t;
}

int main() {
    int c[9]={},cp[9]={},t;
    for(int i=0;i<9;i++){
        cin>>t;
        if(t!=0) cp[i]=4-t;
    }
    for(int A=0;A<4;A++){
        mv[0]=A;
        for(int B=0;B<4;B++){
            mv[1]=B;
            for(int C=0;C<4;C++){
                mv[2]=C;
                for(int D=0;D<4;D++){
                    mv[3]=D;
                    for(int E=0;E<4;E++){
                        mv[4]=E;
                        for(int F=0;F<4;F++){
                            mv[5]=F;
                            for(int G=0;G<4;G++){
                                mv[6]=G;
                                for(int H=0;H<4;H++){
                                    mv[7]=H;
                                    for(int I=0;I<4;I++){
                                        mv[8]=I;
                                        for(int j=0;j<9;j++) c[j]=cp[j]-A*m[0][j]-B*m[1][j]-C*m[2][j]-D*m[3][j]-E*m[4][j]-F*m[5][j]-G*m[6][j]-H*m[7][j]-I*m[8][j];
                                        if(checkClock(c)==0){
                                            int num=A+B+C+D+E+F+G+H+I;
                                            if(mx<num){
                                                mx=num;
                                                for(int j=0;j<9;j++) r[j]=mv[j];
                                            }
                                            if(mx==num){
                                                int te=0;
                                                for(int j=0;j<9;j++)
                                                    if(r[j]<mv[j]) break;
                                                    else if(r[j]>mv[j]){
                                                        te=1;
                                                        break;
                                                    }
                                                if(te==1) for(int j=0;j<9;j++) r[j]=mv[j];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printMoves();
    return 0;
}