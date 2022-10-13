#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int largestRectangleArea(vector<int>& h) {
    vector<int> r(h.size(),h.size());
    stack<int> stk;
    stk.push(0);
    int i=1;

    while(!stk.empty()&& i<h.size()){
        while(!stk.empty() && h[stk.top()] > h[i] ){
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
        i++;
    }
    
    int n = h.size();
    vector<int> l(h.size(),-1);
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

    for(int i=0;i<n;i++){
        cout << r[i]<< " ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout << l[i]<< " ";
    }cout<<endl;


    int ans =0;
    for(int i=0;i<n;i++){
        int x = r[i] - l[i] -1;
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
    int n;
    cin >>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[i] = x;
    }
   cout<< largestRectangleArea(v);
}