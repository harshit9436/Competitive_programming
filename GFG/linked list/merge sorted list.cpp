#include <iostream>
using namespace std;
#include <bits/stdc++.h>



struct ListNode
{
    int val;
    struct ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }

};

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};



//IN place merge, see theory https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if(l1 == NULL) return l2; 
    if(l2 == NULL) return l1;
    if(l1->val > l2->val) std::swap(l1,l2);
    ListNode* res = l1;
    while(l1 != NULL && l2 != NULL) {
        ListNode* temp = NULL;
        while(l1 != NULL && l1->val <= l2->val) {

            temp = l1;//storing last sorted node  
            l1 = l1->next;
        }
        temp->next = l2;
        std::swap(l1,l2);
    }

    return res;
}



//using recursion



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


