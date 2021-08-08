// Evaluate Expression to true boolean parenthesization recursive;
//T  F ^ & |------------>5 symboles in string;

//T^T = false
//F^F = false
//T^F = true
//F^T = true  
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int solve(string s,int i,int j,int istrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(istrue==1){
            return s[i]=='T';
        }else{
            return s[i]=='F';   // i---j ==== sign  : k ==== operator;
        }
        if(istrue==0){
            return s[i]=='T';
        }else{
            return s[i]=='F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }

    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int lt = solve(s,i,k-1,1);
        int lf = solve(s,i,k-1,0);                      //temp answers
        int rt = solve(s,k+1,j,1);
        int rf = solve(s,k+1,j,0);
    if(s[k]=='&'){
        if(istrue==1){
            ans=ans+lt*rt;
        }else{
            ans=ans+lf*rt+lf*rf+lt*rf;
        }
        }else if(s[k]=='|'){
            if(istrue==1){
                ans=ans+lt*rt+lt*rf+lf*rt;
            }else{
                ans=ans+lf*rf;
            }
        }else if(s[k]=='^'){
            if(istrue==1){
                ans=ans+lf*rt+lt*rf;
            }else{
                ans=ans+lt*rt+lf*rf;
            }
        }
    }
    return mp[temp] = ans;
}
int main(){
  string s = "T^F&T";
//   string s = "T|T&F^T";
  cout<<solve(s,0,4,1);
}


/////////////////////////////////////////////////////////////////////////////////////memoization top down///////////////////////////////////////////////////
int t[101][101][2];