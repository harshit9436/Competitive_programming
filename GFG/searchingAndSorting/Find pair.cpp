#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool findPair(int arr[], int size, int n){
    //code
    bool ans = false;
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        
        int target = n + arr[i];
        int index = lower_bound(arr,arr+size,target) -arr;
        if(index != size && index !=i ){
            ans = true;
            break;
        }
    }

    return ans;
    
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,target;
    cin >>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << findPair(arr,n,target);
 
}