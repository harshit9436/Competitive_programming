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




 
    Node* getMiddle(Node *head)
    {
        // Your code here
        Node* slow = head;
        Node * fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
        
    }
    
    
    Node* sortedMerge(Node* head1, Node* head2)  {
        
        Node* ans = (head1->data <=head2->data) ? head1 : head2;
        Node* temp = ans;
        if(head1->data <=head2->data){
            head1 = head1->next;
        }else{
            head2 = head2->next;
        }
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data <=head2->data){
                Node* n = head1;
                temp->next = n;
                temp = n;
                head1 = head1->next;
            }else{
                Node* n = head2;
                temp->next = n;
                temp=n;
                head2 = head2->next;
            }
        }
        
        while(head1!=NULL){
            temp->next =head1;
            temp = head1;
            head1=head1->next;
        }
        while(head2!=NULL){
            temp->next =head2;
            temp = head2;
            head2=head2->next;
        }
        return ans;
        
    }  
    
    Node* mergeSort(Node* head) {
        
    if (head->next == NULL) {
        return head;
    }
    Node * mid = getMiddle(head);
    Node *head2 = mid->next;
    mid->next = NULL;
    Node* finalhead = sortedMerge(mergeSort(head), mergeSort(head2));
    return finalhead;
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
