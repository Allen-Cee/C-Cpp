//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<cmath>

short b[13][32];

class Stu{
public:
    char name[10];
    int m,d;
};

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    Stu s[n];
    for(int i=0;i<n;i++){
        scanf("%s%d%d",s[i].name,&s[i].m,&s[i].d);
        b[s[i].m][s[i].d]++;
    }
    for(int i=1;i<=12;i++) for(int j=1;j<=31;j++) if(b[i][j]>1){
        printf("%d %d ",i,j);
        for(int k=0;k<n;k++) if(s[k].m==i&&s[k].d==j) printf("%s ",s[k].name);
        printf("\n");
    }
    return 0;
}
