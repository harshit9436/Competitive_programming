#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<long long> nextLargerElement(vector<long long> arr, int n){

    vector<long long> ans(n);
    stack<int> stk;

    for(int i=0;i<n;i++){
        while( !stk.empty() && arr[i]>arr[stk.top()]){
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        ans[stk.top()]=-1;
        stk.pop();
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
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        long long x;
        cin >>x;
        arr[i] =x;
    }

    vector<long long > x =nextLargerElement(arr,n);
    for(int i=0;i<x.size();i++){
        cout<< x[i] <<" ";
    }
}