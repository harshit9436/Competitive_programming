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



vector<int> reverseLevelOrder(Node *root){
    if(root==NULL) return {};
    
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    stack<int> stk;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* x =q.front();
            q.pop();
            stk.push(x->data);
            if(x->right){
                q.push(x->right);
            }
            if(x->left){
                q.push(x->left);
            }
        }
    }
    
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
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
