// maximum path sum From leaf node to leaf node;
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left,*right;
};
node* insertnode(node* root,int x){
    node* temp = new node;
    temp->data = x;
    temp->left=temp->right=NULL;
    if(root==NULL){
        root=temp;
        return root;
    }else if(x<=root->data){
        root->left =  insertnode(root->left,x);
    }else{
        root->right = insertnode(root->right,x);
    }
    return root;
}
int solve(node* root,int &res){
    if(root==NULL){
        return 0;
    }
    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = max(l,r)+root->data;                             // max(max(l,r)+root->data,root->data);                            // max(l,r)+1;
    int ans = max(temp,r+l+root->data);                                                                                            // max(temp,l+r+1)
    res = max(ans,res);
    return temp;
}
int main(){
    node* root=NULL;
    int res = INT_MIN;
   root = insertnode(root,1);
   root = insertnode(root,2);
   root = insertnode(root,3);
   root = insertnode(root,4);
   root = insertnode(root,5);
    cout<<solve(root,res);
    cout<<res;
}