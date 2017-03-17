//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
using namespace std;

int tv[1001];

int  main(){
    int T,M,t,v;
    cin>>T>>M;
    while(M-->0){
        scanf("%d%d",&t,&v);
        if(t<=T) for(int j=T-t;j>=0;j--) if(tv[j]+v>tv[j+t]) tv[j+t]=tv[j]+v;
    }
    cout<<tv[T]<<endl;
    return 0;
}
