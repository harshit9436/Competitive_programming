#include <iostream>
using namespace std;
#include <bits/stdc++.h>


bool solve(long long A[], long long n, long long m, long long mid){
    long long ans =0;
    for(long long i=0;i<n;i++){
        ans+= max((A[i]-mid), (long long) 0);
    }
    if(ans>=m){
        return true;
    }else{
        return false;
    }
}


int height(long long A[], long long n, long long m){
    sort(A,A+n);
    long long l = 0 , r = 0;
    for(long long i=0;i<n;i++){
        r+=A[i];
    }
    long long ans=INT_MIN;
    while(l<=r){
        long long mid = (l+r)/2;
        bool pos = solve(A,n,m,mid);
        // cout<< mid<< " "<< pos<< endl;
        if(pos){
            ans = max(ans, mid);
            l = mid+1;
        }else{
            r= mid-1;
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

    long long n,m;
    cin>>n>>m;
    long long arr[n];
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        arr[i]=x;
    }
    cout<< height(arr,n,m);



}
