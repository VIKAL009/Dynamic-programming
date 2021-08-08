#include<bits/stdc++.h>
using namespace std;
int t[7][8];
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
               t[i][j]= 0;
           }
       }
   }
   return t[n][m];
}
int main(){ 
//    int n=6,m=7,i,j;
   string x="GeeksforGeeks";
   string y="GeeksQuiz";
   reverse(x.begin(),x.end());
   reverse(y.begin(),y.end());
//     i=0;
//     j=x.length()-1;
//    while(i<=j){
//      char temp = x[i];
//      x[i]=x[j];
//      x[j]=temp;
//      i++;
//      j--;
//    }
//   i=0;
//   j=y.length()-1;
//    while(i<=j){
//      char temp = y[i];
//      y[i]=y[j];
//      y[j]=temp;
//      i++;
//      j--;
//    }
//    cout<<x<<"  "<<y;

//    string x="abcdgh";
//    string y="abedfhr";
//    LCS(x,y,n,m);      //first we have to reverse the strings 
   cout<<LCS(x,y,x.length(),y.length());      //first we have to reverse the strings 
}