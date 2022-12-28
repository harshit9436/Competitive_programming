#include <iostream>
using namespace std;
#include <bits/stdc++.h>



struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};



    // void inorderTraversal(Node* root, vector<int> &ans){
    //     if(root==NULL) return;
        
    //     inorderTraversal(root->left,ans);
    //     ans.push_back(root->data);
    //     inorderTraversal(root->right,ans);
    // }
    
    Node * solve(Node* root){
        if(root==NULL) return NULL;
        Node* l = solve(root->left);
        Node* r = solve(root->right);
        Node* node = new Node();
        node->data = root->data;
        if(l==NULL){
            node->right = r;
            node->left=NULL;
            if(r!=NULL) r->left = node;
            return node;
        }else{
            Node * temp = l;
            while(temp->right!=NULL){
                temp = temp->right;
            }
            temp->right = node;
            node->left = temp;
            node->right = r;
            if(r!=NULL){
                r->left = node;
            } 
        }
        
        return l;
    }
    
    Node * bToDLL(Node *root)
    {
        //Using inorder

        // vector<int> ans;
        // inorderTraversal(root,ans);
        // // for(int i=;i<ans.size())
        // struct Node* head = new Node();
        // head->data = ans[0];
        // struct Node* temp = head;
        // for(int i=1;i<ans.size();i++){
        //     struct Node* node = new Node();
        //     node->data = ans[i];
        //     temp->right = node;
        //     node->left= temp;
        //     temp=node;
        // }
        
        // return head;

        //using recursion
        return solve(root);
    }


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
}
