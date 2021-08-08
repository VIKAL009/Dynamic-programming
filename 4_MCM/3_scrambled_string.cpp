#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
bool solve(string a,string b)
{
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1 or b.length()<=1){
        return false;
    }

    string temp = a;
    temp.push_back(' ');
    temp.append(b);
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    int n=a.length();
    bool flag = false;
    for(int i=1;i<=n-1;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i)) and solve(a.substr(i,n-i),b.substr(0,n-i)))
        or (solve(a.substr(0,i),b.substr(0,i)) and solve(a.substr(i,n-i),b.substr(i,n-i)))){
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}
int main()
{
    string a = "great";
    string b = "rgeat";
    cout<<solve(a,b);
}