#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int minSwap(int arr[], int n, int k) {
    // Complet the function
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            cnt++;
        }
    }
    // cout<< cnt<<endl;
    
    int i=0,j=cnt-1;
    int bad =0;
    int swap =0;

    for(int l=0;l<=j;l++){
        if(arr[l]>k){
            bad++;
        }
    }
    swap = bad;
    cout<<cnt << " " << swap<<endl;

    while(j<n){
        if(arr[i]>k){
            bad--;
        }
        i++;
        j++;
        if(arr[j]>k){
            bad++;
        }
        swap  = min(swap,bad);
        cout<<swap<< " ";
    }
    
    return swap;
    
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k;
    cin >> n ;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    cin>>k;

    cout<< minSwap(arr,n,k);
}