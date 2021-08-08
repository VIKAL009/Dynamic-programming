// #include<bits/stdc++.h>
// using namespace std;
//     int solve(int f,int e){
//         if(f==0 || f==1){
//             return  f;
//         }
//         if(e==1){
//             return f;
//         }
//         int mn = INT_MAX;
//         for(int k=1;k<=f;k++){
//             int temp = (1 + max(solve(e-1,k-1),solve(e,f-k)));   //max---due to worst case given::
//             mn = min(temp,mn);
//         }
//         return mn;
//     }
// int main(){
//     cout<<solve(4,2);
// }

///*****************************************Egg droping problem******************

// #include<bits/stdc++.h>
// using namespace std;
// int t[101][101];
//     int solve(int f,int e){
//         if(f==0 || f==1){
//             return  f;
//         }
//         if(e==1){
//             return f;
//         }
//         if(t[e][f]!=-1){
//             return t[e][f];
//         }
//         int mn = INT_MAX;
//         for(int k=1;k<=f;k++){
//             int temp = (1 + max(solve(e-1,k-1),solve(e,f-k)));
//             mn = min(temp,mn);
//         }
//         return t[e][f] = mn;
//     }
// int main(){
//     memset(t,-1,sizeof(t));
//     cout<<solve(4,2);
// }

//************************************************++memoization************************************
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
    int solve(int f,int e){
        if(f==0 || f==1){
            return  f;
        }
        if(e==1){
            return f;
        }
        if(t[e][f]!=-1){
            return t[e][f];
        }
        int mn = INT_MAX;
        for(int k=1;k<=f;k++){

            // int temp = (1 + max(solve(e-1,k-1),solve(e,f-k)));
             int low,high;
              if(t[e-1][k-1]!=-1){
                   low = t[e-1][k-1];
              }else{
                   low = solve(e-1,k-1);
                        t[e-1][k-1] = low;
              }
              if(t[e][f-k]!=-1){
                   high = t[e][f-k];
              }else{
                   high = solve(e,f-k);
                  t[e][f-k] = high;
              }

            int temp = (1+max(low,high));

            mn = min(temp,mn);
        }
        return t[e][f] = mn;
    }
int main(){
    memset(t,-1,sizeof(t));
    cout<<solve(4,2);
}
