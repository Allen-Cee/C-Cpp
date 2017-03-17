//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<cmath>

int main() {
    int x,y,n=0;
    scanf("%d%d",&x,&y);
    if(x>y){
        int tmp=x;
        x=y;
        y=tmp;
    }
    for(int i=(x==1)?x+1:x;i<=y;i++){
        bool p=1;
        for(int j=2;j<=sqrt(i);j++) if(i%j==0){
            p=0;
            break;
        }
        if(p) n++;
    }
    printf("%d\n",n);
    return 0;
}
