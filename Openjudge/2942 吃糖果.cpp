//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>

inline int m(int n){
    if(n>0) return m(n-1)+m(n-2);
    else if(n==0) return 1;
    return 0;
}

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    printf("%d\n",m(n-1)+m(n-2));
    return 0;
}
