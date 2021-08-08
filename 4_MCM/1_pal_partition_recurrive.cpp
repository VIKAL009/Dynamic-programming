// // palindrome partitioning recursive solution;
// #include<bits/stdc++.h>
// using namespace std;
// bool ispal(string s,int i,int j){
//     string z;
//     for(int k=i;k<=j;k++){
//         z.push_back(s[k]);
//     }
//     string y = z;
//     reverse(z.begin(),z.end());
//     if(z==y){
//         return true;
//     }else{
//         return false;
//     }
// }
// int solve(string s,int i,int j){
//      if(i>=j){
//          return 0;
//      }
//     if(ispal(s,i,j)){
//         return 0;
//     }
//      int mi=INT_MAX;
//      for(int k=i;k<j;k++){
//            int temp = (1+solve(s,i,k)+solve(s,k+1,j));
//            mi = min(mi,temp);
//      }
//        return mi;
// }
// int main(){
//     string s = "nitik";
//     // string s = "geek";
//    int i=0,j=s.length()-1;
//    cout<<solve(s,i,j);
// //    cout<<ispal(s,i,j);
// }

// palindrome partitioning memoization solution;


// #include<bits/stdc++.h>
// using namespace std;
// int static t[101][101];
// bool ispal(string s,int i,int j){
//     string z;
//     for(int k=i;k<=j;k++){
//         z.push_back(s[k]);
//     }
//     string y = z;
//     reverse(z.begin(),z.end());
//     if(z==y){
//         return true;
//     }else{
//         return false;
//     }
// }
// int solve(string s,int i,int j){
//      if(i>=j){
//          return 0;
//      }
//     if(ispal(s,i,j)){
//         return 0;
//     }if(t[i][j]!=-1){
//         return t[i][j];
//     }
//      int mi=INT_MAX;
//      for(int k=i;k<j;k++){
//            int temp = (1+solve(s,i,k)+solve(s,k+1,j));
//            mi = min(mi,temp);
//      }
//        return  t[i][j] = mi;
// }
// int main(){
//     memset(t,-1,sizeof(t));
//     // string s = "nitik";
//     string s = "geek";
//    int i=0,j=s.length()-1;
//    cout<<solve(s,i,j);
// }

// palindrome partitioning memoization solution with optimization;

#include<bits/stdc++.h>
using namespace std;
int static t[101][101];
bool ispal(string s,int i,int j){
    string z;
    for(int k=i;k<=j;k++){
        z.push_back(s[k]);
    }
    string y = z;
    reverse(z.begin(),z.end());
    if(z==y){
        return true;
    }else{
        return false;
    }
}
int solve(string s,int i,int j){
     if(i>=j){
         return 0;
     }
    if(ispal(s,i,j)){
        return 0;
    }if(t[i][j]!=-1){
        return t[i][j];
    }
     int mi=INT_MAX;
     for(int k=i;k<j;k++){
            int left,right;

        //    int temp = (1+solve(s,i,k)+solve(s,k+1,j));
        if(t[i][k]!=-1){
            left = t[i][k];
        }else{
            t[i][k] = left=solve(s,i,k);
        }
        if(t[k+1][j]!=-1){
            right = t[k+1][j];
        }else{
            t[k+1][j] = right=solve(s,k+1,j);
        }

           int temp = (1+left+right);

           mi = min(mi,temp);
     }
       return  t[i][j] = mi;
}
int main(){
    memset(t,-1,sizeof(t));
    // string s = "nitik";
    string s = "geek";
   int i=0,j=s.length()-1;
   cout<<solve(s,i,j);
}
