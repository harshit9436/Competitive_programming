#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int kthElement(int arr1[], int arr2[], int n, int m, int k){

    // int i=0 ,j=0 , cnt=0;
    // while(i<n && j<m){
    //     if(cnt==k-1){
    //         return min(arr1[i],arr2[j]);
    //     }
    //     if(arr1[i]<arr2[j]){
    //         i++;
    //         cnt++;
    //     }else{
    //         j++;
    //         cnt++;
    //     }
    // }
    
    // if(i==n){
    //     return arr2[k-n-1];
    // }else{
    //     return arr1[k-m-1];
    // }
    

    int l=max(0,k-m),r=min(n, k);
    int l1=0,r1=n-1;
    int l2=0,r2=m-1;
    while(l<=r){
        int mid = (l+r)/2;
        
        l1 = (mid==0) ? INT_MIN : arr1[mid-1] ; 
        r1 =(mid==n) ? INT_MAX : arr1[mid] ;
        l2 = (k-mid==0)? INT_MIN : arr2[k-mid-1];
        r2 = (k-mid==m)? INT_MAX : arr2[k-mid];
        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }else{
            if(l1>r2){
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        
        
        
    }
    return 0;
    
}