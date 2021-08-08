// 7. Matrix chain multiplicatiom(7);
// 1.MCM
// 2.printing MCM
// 3.Evaluation expn to true/boolean paranthesization
// 4.Min/Max value of an expn
// 5.Palindromic partitioning
// 6.scramble string
// 7.egg droping problem

// 1.)  find i and j;
// 2.)  base condition;
// 3.)  k loop;
// 4.)  temp<->min<->max;

// ////////////////////////////REcursive approach///////////////////////////////////////////////////////////////////////////////////////////

// #include<bits/stdc++.h>
// using namespace std;
// int solve(int arr[],int i,int j){
//      if(i>=j){
//          return 0;
//      }
//      int mi=INT_MAX;
//      for(int k=i;k<j;k++){
//            int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
//            mi = min(mi,temp);
//      }
//        return mi;
// }
// int main(){
// //    int arr[]={40,20,30,10,30},n=5;   //26000
//    int arr[]={10,20,30,40,30},n=5;      //30000
//    int i=1,j=n-1;
//    cout<<solve(arr,i,j);
// }

/////////////////////////////////////////Memoization/////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int solve(int arr[],int i,int j){
     if(i>=j){
         return 0;
     }
     if(t[i][j]!=-1){
         return t[i][j];
     }
     int mi=INT_MAX; 
     for(int k=i;k<j;k++){
           int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
           mi = min(mi,temp);
     }
       return t[i][j] = mi;
}
int main(){
    memset(t,-1,sizeof(t));
//    int arr[]={40,20,30,10,30},n=5;   //26000
   int arr[]={10,20,30,40,30},n=5;      //30000
   int i=1,j=n-1;
   cout<<solve(arr,i,j);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
