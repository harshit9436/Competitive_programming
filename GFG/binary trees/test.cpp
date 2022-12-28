#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int evaluatePostfix(string S)
{
    // Your code here
    int ans=0;
    stack<int> stk;
    for(int i=0;i<S.size();i++){
        if(S[i]!='+' && S[i]!='-' && S[i]!='*' && S[i]!='/' ){
            int x = S[i]-'0';
            stk.push(x);
            // cout << "fjfj";
        }else{
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            // cout<<"fhfj;";
            cout << a << " " << b<< endl;
            if(S[i]=='+')ans = a+b;
            if(S[i]=='-')ans = b-a;
            if(S[i]=='*')ans = a*b;
            if(S[i]=='/')ans = b/a;
            
            stk.push(ans);
        }
    }
    return stk.top();
}

int main(){

        #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s = "231*+9-";
    cout << evaluatePostfix(s);
}