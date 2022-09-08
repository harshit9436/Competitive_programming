#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int getMinDiff(int arr[], int n, int k) {
        // code here
    sort(arr,arr+n);
    int ans = arr[n-1]-arr[0];
    int mini = -1; int maxi = INT_MAX;
    
    for(int i=1;i<n;i++){
        if(arr[i]<k){
            continue;
        }else{
            mini = min(arr[0]+k,arr[i]-k);
            maxi = max(arr[n-1]-k,arr[i-1]+k);
        }
        ans = min(ans,maxi-mini);
    }
    return ans;
}

int main(){
    int k, n;
    cin >>k >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    getMinDiff(arr,n,k);

}