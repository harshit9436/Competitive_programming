#include <iostream>
using namespace std;
#include <bits/stdc++.h>



struct Node
{
    int data;
    struct Node* left;
    struct Node* right;


    Node(int x){
        data = x;
        left = NULL;
        right=NULL;
    }

};


vector <int> zigZagTraversal(Node* root)
{
    
    if(root==NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    // bool first = true; 
    int b=0;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            Node *x =q.front();
            q.pop();
            temp.push_back(x->data); 
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        if(b==1){
            reverse(temp.begin(),temp.end());
        }
        
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        
        b = b^1;
    }
    
    return ans;
    
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