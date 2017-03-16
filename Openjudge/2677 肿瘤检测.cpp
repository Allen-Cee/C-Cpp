#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    int area=0;
    int perimeter=0;
    cin>>n;
    int tumour[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tumour[i][j];
            if(tumour[i][j]<=50) ++area;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tumour[i][j]<=50){
                if(i==0||i==n-1||j==0||j==n-1){
                    ++perimeter;
                    continue;
                }
                if((i!=0&&i!=n-1&&j!=0&&j!=n-1)&&(tumour[i-1][j]>50||tumour[i+1][j]>50||tumour[i][j-1]>50||tumour[i][j+1]>50)) ++perimeter;
            }
        }
    }
    cout<<area<<" "<<perimeter<<endl;
    return 0;
}