#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// IMPORTANT question using the concept of merge sort
long long merge(long long arr[], long long l, long long m , long long r){
    long long a = m-l+1;
    long long b = r-m;
    long long cnt=0;
    long long arr1[a], arr2[b];
    for(long long i=0;i<a;i++){
        arr1[i] = arr[l+i];
    }
    for(long long i=0;i<b;i++){
        arr2[i] = arr[m+1+i];
    }
    
    long long k=l, i=0,j=0;
    while(i<a && j<b){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }else{
            arr[k]= arr2[j];
            cnt+= a-i;
            j++;
        }
        k++;
    }
    while(i<a){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<b){
        arr[k]=arr2[j];
        j++;
        k++;
    }
    return cnt;
}

    
void mergeSort(long long arr[], long long l, long long r, long long &cnt) {
  if (l < r) {
    long long m = (l+r) / 2;
    mergeSort(arr, l, m,cnt);
    mergeSort(arr, m + 1, r,cnt);
    cnt += merge(arr, l, m, r);
  }
}

long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long cnt=0;
        mergeSort(arr,0,N-1,cnt);
        return cnt;
    }
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("zinput.txt" , "r" , stdin);
    //     freopen("zoutput.txt" , "w" , stdout);
    // #endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    long long arr[5] = {2,4,1,3,5};
    cout<< inversionCount(arr,5);
}
