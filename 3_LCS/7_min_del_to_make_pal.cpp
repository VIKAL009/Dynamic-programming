// Minimum number of operations(deletion) in a string to make it longest palindrom subsequence (lps);
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
           if(a[i-1]==b[j-1]){
               t[i][j]= (1+t[i-1][j-1]);
           }else{
               t[i][j]= max(t[i][j-1],t[i-1][j]);
           }
       }
   }
   return t[n][m];
}
int main(){
   int n=6,m=6;
   string y="agbcba";
   string x=y;
   reverse(y.begin(),y.end());
   cout<<n-LCS(x,y,n,m);
}