#include <iostream>
using namespace std;
#include <bits/stdc++.h>


long long getMaxArea(long long h[], int n){
    vector<int> r(n,n);
    stack<int> stk;
    stk.push(0);
    int i=1;

    while(!stk.empty()&& i<n){
        while(!stk.empty() && h[stk.top()] > h[i] ){
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
        i++;
    }
    vector<int> l(n,-1);
    stack<int> stk2;
    i=n-2;
    stk2.push(n-1);

    while(!stk2.empty()&& i>=0){
        while(!stk2.empty() && h[stk2.top()] > h[i] ){
            l[stk2.top()] = i;
            stk2.pop();
        }
        stk2.push(i);
        i--;
    }   


    long long ans =0;
    for(int i=0;i<n;i++){
        long long x = r[i] - l[i] -1;
        ans = max(ans, x*h[i]);
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
}