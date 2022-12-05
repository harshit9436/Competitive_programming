#include <iostream>
using namespace std;
#include <bits/stdc++.h>



bool allocate(int A[], int N, int M, int mid){
    int ans=1;
    sort(A,A+N);

    // int i=0;
    // while(i<N){
    //     int cnt=0;
    //     while(true){
    //         if(cnt>mid){
    //             ans++;
    //             break;
    //         }
    //         if(A[i]>mid){
    //             return false;
    //         }
    //         cnt +=cnt+A[i];
    //         i++;
    //     }
    // }
    
    int cnt=0;
    for(int i=0;i<N;i++){
        if(cnt+A[i]<=mid){
            cnt+=A[i];
        }else{
            if(A[i]>mid){
                return false;
            }
            cnt=A[i];
            ans++;
            cout<< ans << " "<<i <<endl;
        }
    }
    
    if(ans>M){
        return false;
    }else{
        return true;
    }
}


int findPages(int A[], int N, int M) {
    int l , r=0;
    sort(A,A+N);
    l = A[0];
    for(int i=0;i<N;i++){
        r+=A[i];
    }

    int ans=INT_MAX;
    while(l<=r){
        int mid = (l+r)/2;
        bool b = allocate(A,N,M,mid);
        cout<< mid << " "<< b << " " << l<< " " <<allocate(A,N,M,24) <<endl;
        if(b){
            ans = min(ans,mid);
            r = mid-1;
        }else{
            l=mid+1;
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

    int n,m;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    cin>>m;

    cout<< allocate(arr,n,m,24);
}
