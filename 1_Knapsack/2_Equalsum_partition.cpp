#include<bits/stdc++.h>
using namespace std;
bool t[101][101];
bool subsetsum(int arr[],int n,int W){
   for(int i=1;i<n+1;i++){
       for(int j=1;j<W+1;j++){
        if(arr[i-1]<=W){
            t[i][j]= t[i-1][j] or t[i-1][j-arr[i-1]];
        }else{
            t[i][j]=t[i-1][j];
        }
       }
   }
   return t[n][W];
}
bool Equalsump(int arr[],int n,int sum){
    if(sum%2!=0){
        return false;
    }else{
        sum/=2;
       return subsetsum(arr,n,sum);
    }
}
int main(){
    int arr[]={2,7,8,3,10},n=5;
     int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
   for(int i=0;i<n+1;i++){
       for(int j=0;j<sum+1;j++){
           if(i==0){
               t[i][j]=false;
           }
           if(j==0){
           t[i][j]=true;
           }      
       }
   }
   cout<<Equalsump(arr,n,sum);
}