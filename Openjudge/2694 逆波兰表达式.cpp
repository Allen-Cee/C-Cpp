#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

double rePo(){
    char s[20];
    cin>>s;
    switch(s[0]){
        case '+':
            return rePo()+rePo();
            break;
        case '*':
            return rePo()*rePo();
            break;
        case '-':
            return rePo()-rePo();
            break;
        case '/':
            return rePo()/rePo();
            break;
        default:
            return atof(s);
    }
}

int main() {
    printf("%f\n",rePo());
    return 0;
}