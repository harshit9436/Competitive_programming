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


int find(int in[] ,int x, int n){
    for(int i=0;i<n;i++){
        if(in[i]==x){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int pre[], int n ,int &index, int l, int r){
    if(index>=n|| l>r){
        return NULL;
    }
    int x = pre[index];
    index++;
    int pos = find(in,x,n);
    Node* root = new Node(x);
    root->left = solve(in,pre,n,index,l,pos-1);
    root->right = solve(in,pre,n,index,pos+1,r);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int index= 0;
    return solve(in,pre,n,index,0,n-1);
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
