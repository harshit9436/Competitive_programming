#include <iostream>
using namespace std;
#include <bits/stdc++.h>



struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};



//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

struct Node* reverse(struct Node *head)
{
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
    }

    return prev;
}


Node *compute(Node *head)
{
    Node* temp = reverse(head);
    head = temp;
    temp = temp->next;
    Node* tail = head;
    int x = head->data;
    while(temp!=NULL){
        if(temp->data < x){
            tail->next = temp->next;
            temp->next=NULL;
            temp = tail->next;
        }else{
            x = max(x,temp->data);
            tail = temp;
            temp = temp->next;
        }
    }
    return reverse(head);
    
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
