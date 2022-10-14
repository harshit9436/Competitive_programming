#include <iostream>
using namespace std;
#include <bits/stdc++.h>


long long trappingWater(vector<int> arr, int n){
        // code here
        vector<int> larger(n,-1), smaller(n,-1);
        int maxi = arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxi = max(maxi,arr[i]);
            if(maxi ==arr[i]){
                larger[i]=-1;
            }else{
                larger[i] = maxi;
            }
        }
        maxi = arr[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi,arr[i]);
            if(maxi==arr[i]){
                smaller[i] =  -1;
            }else{
                smaller[i] = maxi;
            }
        }


        long long ans=0;
        for(int i=0;i<n;i++){
            int h = min(larger[i],smaller[i]);
            int k = (long long)max(h-arr[i] , 0);
            ans += k;
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        arr[i] =x;
    }

    cout <<  trappingWater(arr,n);

}
