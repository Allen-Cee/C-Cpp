#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int tumour[n][n];
    int width=0,height=0,a=0,b=0;
    int check=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tumour[i][j];
            if(tumour[i][j]==0&&check==0){
                a=i;
                b=j;
                check=1;
            }
        }
    }
    for(int i=a;i<n;i++){
        if(tumour[i][b]==0) height++;
    }
    for(int j=b;j<n;j++){
        if(tumour[a][j]==0) width++;
    }
    if(width>2&&height>2) cout<<(width-2)*(height-2)<<endl;
    else cout<<0<<endl;
    return 0;
}