// 1. 0-1 knapsack(6);             1)Subset sum(T/F)                        2)Equal sum partition(T/F)                         3)Count of subset sum(0/1) with given sum  
// 2. unbounded napsack(5);        4)Minimum subset sum difference(0/1)     5)Count of subset sum with given difference(0/1)   6)Target sum(0/1)+-+-+-
// 3. fibonacii(7);
// 4. LCS(15);
// 5. LIS(10);
// 6. kdanes algorithm(6);
// 7. Matrix chain multiplication(7);
// 8. DP on trees(4)
// 9. DP on grid(14);
// 10.others(5);
//******************************************************************************************************************************************

//DP---------------->1.)Recursive----->           a.)Memoization top-down                                            b.)bottom-up 
//
//                     base case                     base case                                                 iterative + initialization
//                        RC(2)                      RC(2)+storage(matrix)                                            only_matrix

// 1--->Choices       2--->optimal--optimization---min_max---->

//    Items--->properties-------w[n]-----val[n]-----W----n    


//  a)----0 1 knapsack      b)--------fractional knapsack      c)-------unbounded knapsack


//*************************************************************Knapsack***********************************************************************

#include<bits/stdc++.h>
using namespace std;

//*****************************************************************************************Code-1****simple recursive;

// int knapsack(int w[],int val[],int n,int W){
//      if(n==0 or W==0){
//          return 0;
//      }else if(w[n-1]<=W){
//          return max((val[n-1]+knapsack(w,val,n-1,W-w[n-1])),knapsack(w,val,n-1,W));
//      }else{
//          return knapsack(w,val,n-1,W);
//      }
// }
// int main(){
//     int n,W;
//     int w[]={10,20,30},val[]={60,100,120};
//     // int w[]={1,2,3,4,5},val[]={5,4,3,2,1};
//     cout<<knapsack(w,val,5,30);
// }
//********************************************************************************Code-2****recursive with memoization;
// int t[101][101];
// int knapsack(int w[],int val[],int n,int W){
//      if(n==0 or W==0){
//          return 0;
//      }
//      if(t[n][W]!=-1){
//          return t[n][W];
//      }
//      else if(w[n-1]<=W){
//          return t[n][W] = max((val[n-1]+knapsack(w,val,n-1,W-w[n-1])),knapsack(w,val,n-1,W));
//      }else{
//          return t[n][W] = knapsack(w,val,n-1,W);
//      }
   
    //  else if(w[n-1]<=W){
    //      return  max((val[n-1]+knapsack(w,val,n-1,W-w[n-1])),knapsack(w,val,n-1,W));
    //  }else{
    //      return  knapsack(w,val,n-1,W);
    //  }
// }
// int main(){
    //  memset(t,-1,sizeof(t));
// for(int i=0;i<100;i++){
//     for(int j=0;j<100;j++){
//         t[i][j]=-1;
//     }
// }

//  int w[]={10,20,30},val[]={60,100,120};
    // int w[]={1,2,3,4,5},val[]={5,4,3,2,1};
    // cout<<knapsack(w,val,5,15);
    // cout<<knapsack(w,val,3,50);

// }
//********************************************************************************Code-3****recursive with bottom up;
// int t[101][101];
// int main(){
//     // int w[]={10,20,30},val[]={60,100,120},n=3,W=50;
//     int w[]={1,2,3,4,5},val[]={1,2,3,4,5},n=5,W=15;
//     for(int i=0;i<n+1;i++){
//         for(int j=0;j<W+1;j++){
//             if(i==0 or j==0){
//             t[i][j]=0;
//             }
//         }
//     }
//     for(int i=1;i<n+1;i++){
//         for(int j=1;j<W+1;j++){
//             if(w[i-1]<=j){
//                t[i][j]= max(t[i-1][j],val[i-1]+t[i-1][j-w[i-1]]);
//             }else{
//                 t[i][j]=t[i-1][j];
//             }
//         }
//     }
//     cout<<t[n][W];
// }
// *****************************************************DP intro complete**********************************************








///coin change 2
///Lcs 2


// super concept
// * 2 or 1 array + capacity   knapscak (min+max);
//* 2 string + min max(lcs);

// /how to match    i/p    Q    o/p     if input output same Q==same