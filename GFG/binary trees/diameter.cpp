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


//pass height to not calculate it at each step - > from O(N^2) to O(N)
int solve(Node* root, int * h){
    if(root==NULL){
        *h =0;
        return 0;  
    } 
    int hl=0, hr=0;
    
    int x = max(solve(root->left, &hl), solve(root->right,&hr));
    *h = 1+ max(hl,hr);
    return max(1 + hl + hr , x);
    
}

int diameter(Node* root) {
    int h=0;
    return solve(root,&h);
    
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
