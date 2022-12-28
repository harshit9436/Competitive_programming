#include <iostream>
using namespace std;
#include <bits/stdc++.h>


class Node{
    public:
        int data;
        Node* next;
    
};

void print(Node* head){
    Node* temp = head;
    cout<<temp->data << " ";
    temp = temp->next;
    while(temp!=head){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node* temp =head->next;
    int cnt=1;
    while(temp!=head){
        cnt++;
        temp=temp->next;
    }
    
    cnt = (cnt+1)/2;
    int x=0;
    temp=head;
    while(x < cnt-1 ){
        x++;
        temp=temp->next;
    }
    Node* head2 = temp->next;
    temp->next = head;
    head1_ref = &head;
    // cout<< cnt << " " << temp->data;
    // print(head);
    temp = head2;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = head2;
    head2_ref = &head2;
    // print(head2);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n=0;
    cin>>n;
    Node * head =NULL;
    Node * tail =NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>> x;
        Node* node = new Node();
        (*node).data = x;
        (*node).next = NULL;
        if(head==NULL){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }
    tail->next = head;
    // cout<< head->data;
    // head = recursiveInsert(head,5 , 7 );
    // print(head);
    splitList(head,NULL,NULL);

    return 0;
}
