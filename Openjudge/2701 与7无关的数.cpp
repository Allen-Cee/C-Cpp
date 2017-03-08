#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int addup=0;
    for(int i=1;i<n+1;i++){
        if(i%7==0||i%10==7||(i<80&&i>=70)) continue;
        else addup+=i*i;
    }
    cout<<addup<<endl;
    return 0;
}