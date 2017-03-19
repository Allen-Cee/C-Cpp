//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;

int comp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char s[21];
    while(cin.getline(s,21)){
        int n[20],len=(int)strlen(s),num=0;
        while(len-->0) if(s[len]>='0'&&s[len]<='9') n[num++]=s[len];
        qsort(n,num,sizeof(n[0]),comp);
        while(num--) cout<<setw(4)<<n[num]-'0';
        cout<<endl;
    }
    return 0;
}
