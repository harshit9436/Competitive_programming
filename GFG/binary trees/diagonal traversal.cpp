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

vector<int> diagonal(Node *root){
    map<int, vector<int> >mp;
    queue<Node*> q;
    q.push(root);
    int cnt=1;
    vector<int> ans;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node * node= q.front();
            Node* temp = node;
            q.pop();
            ans.push_back(temp->data);
            while(temp!=NULL){
                if(temp->right){
                    ans.push_back(temp->right->data);
                }
                if(temp->left){
                    q.push(temp->left);
                }   
                temp=temp->right;
            }
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
