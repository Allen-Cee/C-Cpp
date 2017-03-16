#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int num[3]={0,0,0},input;
    while(n-->0){
        cin>>input;
        if(input==1) num[0]++;
        else if(input==5) num[1]++;
        else if(input==10) num[2]++;
    }
    cout<<num[0]<<"\n"<<num[1]<<"\n"<<num[2]<<endl;
    return 0;
}