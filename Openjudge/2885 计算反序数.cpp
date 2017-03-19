//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char n[10];
    while(cin>>n){
        int be=(int)strlen(n)-1,en=(n[0]=='-')?1:0;
        while(n[be]=='0'&&be>en) be--;
        if(en&&n[be]>'0') cout<<"-";
        for(int i=be;i>=en;i--) cout<<n[i];
        cout<<endl;
        memset(n,'\0',sizeof(n));
    }
    return 0;
}
