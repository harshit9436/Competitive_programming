
#include <iostream>
using namespace std;
#include <bits/stdc++.h>



struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

struct node *reverse (struct node *head, int k)
{ 
    
    if(head==NULL){
        return NULL;
    }
    
    node* prev = NULL;
    node* curr = head;
    node* next;
    int cnt = 0;    
    while(curr!=NULL && cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
        cnt++;
    }
    
    node* temp = reverse(curr,k);
    node* x = prev;
    while(x->next!=NULL){
        x = x->next;
        
    }
    x->next = temp;
    
    
    

    return prev;
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
