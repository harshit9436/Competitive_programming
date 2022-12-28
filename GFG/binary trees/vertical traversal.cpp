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


vector<int> verticalOrder(Node *root)
{
    if (!root)
    return {};
    map<int, vector<int> > m;
    int hd = 0;
    queue<pair<Node*, int> > q;
    q.push({ root, hd });
    
    while (q.size() > 0) {
        int n = q.size();
        for(int i=0;i<n;i++){
            pair<Node*, int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node* node = temp.first;
            m[hd].push_back(node->data);
        
            if (node->left)
                q.push({ node->left, hd - 1 });
            if (node->right)
                q.push({ node->right, hd + 1 });
            }
    }

    vector<int> ans;
    for(auto it=m.begin();it!=m.end();it++){
        vector<int> x = (*it).second;
        for(int i=0;i<x.size();++i){
            ans.push_back(x[i]);
        }
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