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
    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}

Node* recursiveInsert(Node* head , int i, int data){
    if(head==NULL && i!=0){
        return NULL;
    }else{
        if(i==0 ){
            Node * node = new Node();
            node->data = data;
            node->next = head;
            head= node;
            return head;
        }else{
            Node * node = recursiveInsert(head->next,i-1,data);
            head->next = node;
            return head;
        }
    }
}

Node* insert(Node* head , int i, int data){
    int cnt=0;
    Node* temp = head;
        if(i==0){
        Node * node = new Node();
        node->data = data;
        node->next = head;
        head= node;
        return head;
    }

    while(temp!=NULL && cnt<i-1){
        temp = temp->next;
        cnt++;
    }

    if(temp==NULL){

    }else{
        Node * node = new Node();
        node->data = data;
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n=0;
    Node * head =NULL;
    Node * tail =NULL;

    while(true){
        cin>> n;
        // cout<< n;
        if(n==-1){
            break;
        }else{
            Node* node = new Node();
            (*node).data = n;
            (*node).next = NULL;
            if(head==NULL){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
            
        }
    }

    // cout<< head->data;
    head = recursiveInsert(head,5 , 7 );
    print(head);

    return 0;
}
