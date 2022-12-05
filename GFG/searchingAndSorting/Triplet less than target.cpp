#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    long long ans =0;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        long long target = sum-arr[i];
        int j = i+1 , k = n-1;
        while(j<=k){
            if(arr[j]+arr[k] < target){
                ans += k-j;
                j++;
            }else{
                k--;
            }
        }
    }
    return ans;
    
}
        