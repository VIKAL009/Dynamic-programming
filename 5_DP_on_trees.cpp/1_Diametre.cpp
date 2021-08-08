#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left,*right;
    node (int x){
        data = x;
        left = right = NULL;
    }
};
// node* insertnode(node* root,int x){
//     node* temp = new node;
//     temp->data = x;
//     temp->left=temp->right=NULL;
//     if(root==NULL){
//         root=temp;
//         return root;
//     }else if(x<=root->data){
//         root->left =  insertnode(root->left,x);
//     }else{
//         root->right = insertnode(root->right,x);
//     }
//     return root;
// }
// void preorder(node* root){
//     if(root==NULL){
//         return;
//     }
//     preorder(root->left);
//     cout<<root->data<<" ";
//     preorder(root->right);
// }
int solve(node* root,int &res){
    if(root==NULL){
        return 0;
    }
    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = max(l,r)+1;
    int ans = max(temp,r+l+1);  // temp <= r+l+1 redundent::
    res = max(res,ans);
    return temp;

}
int main(){
    node* root=NULL;
    int res = INT_MIN;
//    root = insertnode(root,4);
//    root = insertnode(root,5);
//    root = insertnode(root,2);
//    root = insertnode(root,1);
//    root = insertnode(root,3);
//    root = insertnode(root,1);
//    root = insertnode(root,2);
//    root = insertnode(root,3);
//    root = insertnode(root,4);
//    root = insertnode(root,5);
//    preorder(root);
    root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    cout<<solve(root,res);
    cout<<res;
}