//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>

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
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            scanf("%d",&tri[i][j]);
            mark[i][j]=-1;
        }
    }
    printf("%d\n",addmax(0,0));
    return 0;
}
