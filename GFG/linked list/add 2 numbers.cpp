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



struct Node* reverse(struct Node *head){
    
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

//Function to add two numbers represented by linked list.
//list were already reversed , very neat code compared to mine
 Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *dummy = new Node(0); 
        Node *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> data; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            Node *node = new Node(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
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
