#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

char first_left[7],first_right[7],second_left[7],second_right[7],third_left[7],third_right[7];
int weight[13],confirm[13];

string check_first(){
    string even="even",down="down",up="up";
    int left=0,right=0;
    for(int i=0;first_left[i]!='\0';i++){
        left+=weight[first_left[i]-64];
        right+=weight[first_right[i]-64];
    }
    if(left==right) return even;
    else if(left<right) return down;
    else return up;
}

string check_second(){
    string even="even",down="down",up="up";
    int left=0,right=0;
    for(int i=0;second_left[i]!='\0';i++){
        left+=weight[second_left[i]-64];
        right+=weight[second_right[i]-64];
    }
    if(left==right) return even;
    else if(left<right) return down;
    else return up;
}

string check_third(){
    string even="even",down="down",up="up";
    int left=0,right=0;
    for(int i=0;third_left[i]!='\0';i++){
        left+=weight[third_left[i]-64];
        right+=weight[third_right[i]-64];
    }
    if(left==right) return even;
    else if(left<right) return down;
    else return up;
}

void mark_first(){
    for(int i=0;first_left[i]!='\0';i++){
        confirm[first_left[i]-64]=1;
        confirm[first_right[i]-64]=1;
    }
}

void mark_second(){
    for(int i=0;second_left[i]!='\0';i++){
        confirm[second_left[i]-64]=1;
        confirm[second_left[i]-64]=1;
    }
}

void mark_third(){
    for(int i=0;third_left[i]!='\0';i++){
        confirm[third_left[i]-64]=1;
        confirm[third_left[i]-64]=1;
    }
}

int main() {
    string first_result,second_result,third_result;
    int n;
    cin>>n;
    while(n-->0){
        for(int i=1;i<13;i++){
            weight[i]=2;
            confirm[i]=0;
        }
        cin>>first_left>>first_right>>first_result;
        cin>>second_left>>second_right>>second_result;
        cin>>third_left>>third_right>>third_result;
        if(first_result=="even") mark_first();
        if(second_result=="even") mark_second();
        if(third_result=="even") mark_third();
        int light=0;
        for(int i=1;i<13;i++){
            if(confirm[i]!=1) weight[i]=1;
            if(check_first()==first_result){
                if(check_second()==second_result){
                    if(check_third()==third_result){
                        cout<<(char)(64+i)<<" is the counterfeit coin and it is light."<<endl;
                        light=1;
                        break;
                    }
                }
            }
            weight[i]=2;
        }
        for(int i=1;i<13;i++){
            if(light==1) break;
            if(confirm[i]!=1) weight[i]=3;
            if(check_first()==first_result){
                if(check_second()==second_result){
                    if(check_third()==third_result){
                        cout<<(char)(64+i)<<" is the counterfeit coin and it is heavy."<<endl;
                        break;
                    }
                }
            }
            weight[i]=2;
        }
    }
    return 0;
}