//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdlib.h>
#include<memory.h>
using namespace std;

int c1[26],c2[26];

int comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int  main(){
    char s1[101],s2[101];
    int l=0;
    cin>>s1>>s2;
    l=strlen(s1);
    if(l!=strlen(s2)) cout<<"NO\n";
    else{
        while(--l>=0){
            c1[s1[l]-'A']++;
            c2[s2[l]-'A']++;
        }
        qsort(c1,26,sizeof(c1[0]),comp);
        qsort(c2,26,sizeof(c2[0]),comp);
        if(memcmp(c1,c2,sizeof(c1))==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
