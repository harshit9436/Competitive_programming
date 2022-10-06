#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int maxProfit(vector<int>&price){
    //Write your code here..
    
    int n = price.size();
    int l[n];
    vector<int>  r(n,0);
    l[0]= 0;
    int mini = price[0];
    for(int i=1;i<n;i++){
        int profit = price[i] - mini;
        mini = min(mini,price[i]);
        l[i] = max(l[i-1],profit);
    }
    
    reverse(price.begin(),price.end());
    int maxi = price[0];
    r[0]=0;
    for(int i=1;i<n;i++){
        int profit = maxi -price[i];
        maxi = max(maxi,price[i]);
        r[i] = max(r[i-1],profit);
    }
    
    reverse(r.begin(),r.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, l[i]+r[i]);
    }
    // ans = max(ans,max(l[n-1],r[0]));

    for(int i=0;i<n;i++){
        cout<<l[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;

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
    vector<int> price;
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        price.push_back(x);
    }
    cout << maxProfit(price) << endl;
}