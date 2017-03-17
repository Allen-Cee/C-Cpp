//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
using namespace std;

int  main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    long a,b;
    while(cin>>a){
        char c;
        cin>>c>>b;
        if(c=='+') cout<<a+b;
        else cout<<a-b;
        cout<<endl;
    }
    return 0;
}
