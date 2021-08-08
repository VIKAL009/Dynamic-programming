//Longest Repeating subsequence
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int LCS(string a,string b,int n,int m){
    t[n+1][m+1];
   for(int i=0;i<n+1;i++){
       for(int j=0;j<m+1;j++){
           if(i==0 or j==0){
               t[i][j]=0;
           }
       }
   }
   for(int i=1;i<n+1;i++){
       for(int j=1;j<m+1;j++){
           if(a[i-1]==b[j-1] and i!=j){      // ::check:: //
               t[i][j]= (1+t[i-1][j-1]);
           }else{
               t[i][j]= max(t[i][j-1],t[i-1][j]);
           }
       }
   }
   return t[n][m];
}
int main(){
//    int n=8,m=8;
   int n=4,m=4;
//    string x="AABEBCDD";
   string x="aabb";
   string y=x;
   cout<<LCS(x,y,n,m);
}