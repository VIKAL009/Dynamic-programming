//Multiple occurances allow       1) Rod cutting     2)coin change-1    3)coin change-2    4)Max ribbon cut
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int main(){
    // int w[]={10,20,30},val[]={60,100,120},n=3,W=50;
    int w[]={1,2,3,4,5},val[]={1,2,3,4,5},n=5,W=15;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 or j==0){
            t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j){
               t[i][j]= max(t[i-1][j],val[i-1]+t[i][j-w[i-1]]);                    //t[i-1]-------->t[i]
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][W];
}