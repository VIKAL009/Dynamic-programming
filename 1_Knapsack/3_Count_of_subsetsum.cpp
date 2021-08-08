#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int subsetsum(int arr[],int n,int W){
   for(int i=1;i<n+1;i++){
       for(int j=1;j<W+1;j++){
        if(arr[i-1]<=W){
            t[i][j]= t[i-1][j] + t[i-1][j-arr[i-1]];
        }else{
            t[i][j]=t[i-1][j];
        }
       }
   }
   return t[n][W];
}
int main(){
    int arr[]={1,7,8,3,10},n=5,W=11;
   for(int i=0;i<n+1;i++){
       for(int j=0;j<W+1;j++){
           if(i==0){
               t[i][j]=0;
           }
           if(j==0){
           t[i][j]=1;
           }      
       }
   }
   cout<<subsetsum(arr,n,W);
}