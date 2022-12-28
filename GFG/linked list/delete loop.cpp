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



void removeLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        bool b = false;
        while(fast!=NULL && fast->next!=NULL){
            if(slow==fast){
                b = true;
                fast = head;
                break;
            }
            slow = slow->next;
            fast= fast->next->next;
        }
        
        while(b && slow->next!=fast){
            slow=slow->next;
            fast = fast->next;
            
        }
        if(b){
            slow->next=NULL;
        }
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

