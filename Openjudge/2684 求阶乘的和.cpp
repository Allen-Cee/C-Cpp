#include<iostream>
using namespace std;

int main() {
    int n,addup=0,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        num=1;
        for(int j=1;j<=i;j++){
            num*=j;
        }
        addup+=num;
    }
    cout<<addup;
    return 0;
}