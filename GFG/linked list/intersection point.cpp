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

// see question  https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n=0;
    int m=0;
    Node* temp1=head1;
    while(temp1!=NULL){
        n++;
        temp1 = temp1->next;
    }
    
    Node* temp2 = head2;
    while(temp2!=NULL){
        m++;
        temp2 = temp2->next;
    }
    if(n<m){
        Node* temp = head1;
        head1 = head2;
        head2 = temp;
        swap(n,m);
    }
    int k= n-m;
    int cnt=0;
    temp1= head1;
    while(cnt<k){
        cnt++;
        temp1=temp1->next;
    }
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL && temp1!=temp2){
        temp1=temp1->next;
        temp2 = temp2->next;
    }
    if(temp1==NULL){
        return -1;
    }else{
        return temp1->data;
    }
    // return n;

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