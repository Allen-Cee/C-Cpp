#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int addup=0;
    for(int i=1;i<n+1;i++){
        addup+=i*i*i;
    }
    cout<<addup<<endl;
    return 0;
}