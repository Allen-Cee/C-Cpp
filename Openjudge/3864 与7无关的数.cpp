//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int sum=0,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) if(i%7&&i%10!=7&&i/10!=7) sum+=i*i;
    printf("%d\n",sum);
    return 0;
}
