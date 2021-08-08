#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int main(){
    // int w[]={10,20,30},val[]={60,100,120},n=3,W=50;
    // int w[]={25,10,5},n=3,W=25;
    int w[]={1,2,3},n=3,W=5;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(j==0){
            t[i][j]=0;
            }if(i==0){
                t[i][j]=INT_MAX-1;
            }
        }
    }
     for(int j=1;j<W+1;j++){
                    if(j%w[0]==0){
                    t[1][j]=j/w[0];
                } else{
                    t[1][j]=INT_MAX-1;    
           }
        }  
    
    for(int i=2;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j){
               t[i][j]= min((1 + t[i][j-w[i-1]]),t[i-1][j]);                    //t[i-1]-------->t[i]
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    cout<<t[n][W];
}