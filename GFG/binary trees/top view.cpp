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

vector<int> topView(Node *root)
{
    //Your code here
    map<int,int> mp;
    queue<pair<Node*,int> > q;
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int> p = q.front();
        q.pop();
        Node* node = p.first;
        int hd = p.second;
        if(mp.find(hd)==mp.end()){
            mp.insert({hd,node->data});
        }
        if(node->left){
            q.push({node->left,hd-1});
        }
        if(node->right){
            q.push({node->right,hd+1});
        }
    }
    vector<int> ans;
    
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back((*it).second);
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