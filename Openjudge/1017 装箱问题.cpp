#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    while(1){
        int box[6];
        int package=0;
        for(int i=0;i<6;i++){
            cin>>box[i];
        }
        if(box[0]==0&&box[1]==0&&box[2]==0&&box[3]==0&&box[4]==0&&box[5]==0) break;
        if(box[5]>0) package+=box[5];
        if(box[4]>0){
            package+=box[4];
            if(box[0]>box[4]*11){
                box[0]-=box[4]*11;
                //1*1->5*5 unfinished
            }
            else box[0]=0;
        }
        if(box[3]>0){
            package+=box[3];
            if(box[1]>box[3]*5){
                box[1]-=box[3]*5;
                //2*2->4*4 unfinished
            }
            else{
                if(box[0]>(box[3]*5-box[1])*4){
                    box[0]-=(box[3]*5-box[1])*4;
                    //2*2->4*4 finished
                    //1*1->4*4 unfinished
                }
                else box[0]=0;
                box[1]=0;
            }
        }
        if(box[2]>0){
            package+=ceil(box[2]/4.0);
            if(box[2]%4!=0){
                if(box[2]%4==3){
                    if(box[1]>=1){
                        box[1]-=1;
                        if(box[0]>5){
                            box[0]-=5;
                        }
                        else box[0]=0;
                    }
                    else{
                        if(box[0]>9){
                            box[0]-=9;
                        }
                        else box[0]=0;
                    }
                }
                if(box[2]%4==2){
                    if(box[1]>=3){
                        box[1]-=3;
                        if(box[0]>6){
                            box[0]-=6;
                        }
                        else box[0]=0;
                    }
                    else{
                        if(box[0]>18-box[1]*4){
                            box[0]-=18-box[1]*4;
                        }
                        else box[0]=0;
                        box[1]=0;
                    }
                }
                if(box[2]%4==1){
                    if(box[1]>=5){
                        box[1]-=5;
                        if(box[0]>7){
                            box[0]-=7;
                        }
                        else box[0]=0;
                    }
                    else{
                        if(box[0]>27-box[1]*4){
                            box[0]-=27-box[1]*4;
                        }
                        else box[0]=0;
                        box[1]=0;
                    }
                }
            }
        }
        if(box[1]>0){
            package+=ceil(box[1]/9.0);
            if(box[1]%9!=0){
                if(box[0]>36-(box[1]%9)*4){
                    box[0]-=36-(box[1]%9)*4;
                }
                else box[0]=0;
            }
        }
        if(box[0]>0){
            package+=ceil(box[0]/36.0);
        }
        cout<<package<<endl;
    }
    return 0;
}