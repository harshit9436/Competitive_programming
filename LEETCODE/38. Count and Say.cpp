#include <iostream>
using namespace std;
#include <bits/stdc++.h>



string countAndSay(int n) {
    if(n==1){
        return "1";
    }
    if(n==2){
        return "11";
    }
    string x = countAndSay(n-1);
    int c =x[0]-'0';
    int freq = 1;
    // cout << x << " "<< c << " ";
    string ans="";
    for(int i=1;i<x.size();i++){
        if(x[i-1]==x[i]){
            freq++;
        }else{
            ans += to_string(freq) + to_string(c);
            freq=1;
            c = x[i]-'0';
        }
    }
    // cout << ans << " dd";
    ans += to_string(freq) + to_string(c);

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
    cout << countAndSay(n) << endl;
}
