#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int median(vector<vector<int>> &arr, int r, int c){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<r;i++){
        mini = min(mini, arr[i][0]);
        maxi = max(maxi,arr[i][c-1]);
    }
    int n = (r*c+1)/2;
    int i = mini,j=maxi;
    while(i<j){
        int mid =(i+j)/2;
        int cnt=0;
        for(int k=0;k<r;k++){
            cnt+= upper_bound(arr[k].begin(),arr[k].end(),mid) - arr[k].begin();
        }
        if(cnt < n){
            i =mid+1;
        }else{
            j =mid;
        }
    }
    return i;

}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}