#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int n,tri[100][100],mark[100][100];

int addmax(int x,int y){
    if(mark[x][y]!=-1) return mark[x][y];
    if(x==n-1) return tri[x][y];
    else{
        if(addmax(x+1,y)>=addmax(x+1,y+1)){
            mark[x][y]=tri[x][y]+addmax(x+1,y);
            return mark[x][y];
        }
        else{
            mark[x][y]=tri[x][y]+addmax(x+1,y+1);
            return mark[x][y];
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>tri[i][j];
            mark[i][j]=-1;
        }
    }
    cout<<addmax(0,0)<<endl;
    return 0;
}