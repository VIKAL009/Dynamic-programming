#include<bits/stdc++.h>
using namespace std;
bool t[101][101];
vector<bool> subsetsum(int arr[],int n,int W){
   for(int i=1;i<n+1;i++){
       for(int j=1;j<W+1;j++){
        if(arr[i-1]<=W){
            t[i][j]= t[i-1][j] or t[i-1][j-arr[i-1]];
        }else{
            t[i][j]=t[i-1][j];
        }
       }
   }
   vector<bool>vec;
  for(int i=0;i<W+1;i++){
         vec.push_back(t[n][i]);
  }
  return vec;
}
int main(){
    int arr[]={1,2,7},n=3,sum=0,dif=INT_MAX;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int W=sum;
     for(int i=0;i<n+1;i++){
       for(int j=0;j<W+1;j++){
           if(i==0){
               t[i][j]=false;
           }
           if(j==0){
           t[i][j]=true;
           }      
       }
   }
   vector<bool>vec=subsetsum(arr,n,W);
   int k=vec.size()/2;
   for(int i=0;i<k;i++){
       if(vec[i]==true)
           dif=min(dif,sum-2*i);
   }
//    int k=vec.size();
//    for(int i=0;i<k;i++){
//        if(vec[i]==true)
//            dif=min(dif,abs(sum-2*i));
//    }
   cout<<dif<<" ";
}