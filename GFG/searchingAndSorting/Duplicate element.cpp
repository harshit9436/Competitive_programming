#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int *findTwoElement(int *arr, int n) {
    // code here
    int dup=0;
        for(int i=0;i<n;i++){
            int x = abs(arr[i]);
            if(arr[x-1] <0){
                dup = x;
            }
            arr[x-1] = -1*arr[x-1];
        }
        // for(int i=0;i<n;i++){
        //     cout<< arr[i] << " ";
        // }
        // cout<<endl;
        
        
        // for(int i=0;i<n;i++){
        //     if(arr[i]>0){
        //         dup = arr[i];
        //         break;
        //     }
        // }
        
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += abs(arr[i]);
        }
        long long x = ((long long ) n*( (long long ) n+1))/2;
        int mis = x- sum;
        // int mis = (int) (x - sum + dup);
        mis += dup;
        // cout << sum << " "<< x;
        int* ans = new int[2] ;
        ans[0] = dup ; 
        ans[1]= mis;

        return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    findTwoElement(arr,n);
}