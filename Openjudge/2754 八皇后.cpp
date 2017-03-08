#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
using namespace std;

int chessboard[8][8];
int count_c=0;
int result_string[92];

void clearGame(int chessboard[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chessboard[i][j]=0;
        }
    }
}

void printGame(int chessboard[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chessboard[i][j]==8) result_string[count_c]+=pow(10,7-i)*(j+1);
        }
    }
    count_c++;
    //cout<<result[count_c]<<"\n";
    clearGame(chessboard);
}

int checkQueen(int x,int y,int chessboard[8][8]){
    int targ_x=x;
    int targ_y=y;
    int result=0;
    while(++targ_x<8&&++targ_y<8)
        if(chessboard[targ_x][targ_y]==8) result=1;
    targ_x=x;
    targ_y=y;
    while(++targ_x<8&&--targ_y>=0)
        if(chessboard[targ_x][targ_y]==8) result=1;
    return result;
}

void checkGame(int chessboard[8][8]){
    int result=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chessboard[i][j]==8)
                if(checkQueen(i,j,chessboard)==1){
                    result=1;
                    break;
                }
        }
    }
    if(result==0) printGame(chessboard);
    else clearGame(chessboard);
}

void initGame(int position[]){
    int col;
    for(int i=0;i<8;i++){
        col=position[i];
        chessboard[i][col]=8;
    }
    checkGame(chessboard);
}

void generateGame(int position[],int start){
    int p_backup[8]={0,1,2,3,4,5,6,7};
    for(int i=start;i<8;i++){
        p_backup[i]=position[i];
    }
    for(int i=start;i<8;i++){
        if(start==7){
            initGame(position);
            break;
        }
        int tmp=position[start];
        position[start]=position[i];
        position[i]=tmp;
        generateGame(position,start+1);
        for(int i=start;i<8;i++){
            position[i]=p_backup[i];
        }
    }
}

int comp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int main() {
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chessboard[i][j]=0;
        }
    }
    int position[8]={0,1,2,3,4,5,6,7};
    generateGame(position,0);
    qsort(result_string,92,sizeof(int),comp);
    int n,num;
    cin>>n;
    while(n-->0){
        cin>>num;
        cout<<result_string[num-1]<<endl;
    }
    return 0;
}
