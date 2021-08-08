// ****************************************************Recursive********************************************************************
// #include<bits/stdc++.h>
// using namespace std;
// int LCS(string a,string b,int n,int m){
//     if(n==0 or m==0){
//         return 0;
//     }else if(a[n-1]==b[m-1]){
//         return (1+LCS(a,b,n-1,m-1));
//     }else{
//         return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
//     }
// }
// int main(){
//    int n=6,m=7;
//    string x="abcdgh";
//    string y="abedfhr";
//    cout<<LCS(x,y,n,m);
// }

// ****************************************************Memoization********************************************************************
// #include<bits/stdc++.h>
// using namespace std;
// int t[101][101];
// int LCS(string a,string b,int n,int m){
//     if(n==0 or m==0){
//         return 0;
//     }
//     if(t[n][m]!=-1){
//         return t[n][m];
//     }
//     if(a[n-1]==b[m-1]){
//         return  t[n][m] = (1+LCS(a,b,n-1,m-1));
//     }else{
//         return t[n][m] = max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
//     }
// }
// int main(){
//     memset(t,-1,sizeof(t));
//    int n=6,m=7;
//    string x="abcdgh";
//    string y="abedfhr";
//    cout<<LCS(x,y,n,m);
// }
// ****************************************************Top down********************************************************************
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
   int n=6,m=7;
   string x="abcdgh";
   string y="abedfhr";
   cout<<LCS(x,y,n,m);
}