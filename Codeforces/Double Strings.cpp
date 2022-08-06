
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*

You are given n strings s1,s2,…,sn of length at most 8.
For each string si, determine if there exist two strings sj and sk such that si=sj+sk. That is, si is the concatenation of sj and sk. Note that j can be equal to k.
Recall that the concatenation of strings s and t is s+t=s1s2…spt1t2…tq, where p and q are the lengths of strings s and t respectively. For example, concatenation of "code" and "forces" is "codeforces".

Input

]The first line contains a single integer t (1≤t≤104) — the number of test cases.
The first line of each test case contains a single integer n (1≤n≤105) — the number of strings.
Then n lines follow, the i-th of which contains non-empty string si of length at most 8, consisting of lowercase English letters. Among the given n strings, there may be equal (duplicates).
The sum of n over all test cases doesn't exceed 105.

Output
For each test case, output a binary string of length n. The i-th bit should be 1 if there exist two strings sj and sk where si=sj+sk, and 0 otherwise. Note that j can be equal to k.

*/

void solve(vector<string> & arr){
    
    //BRUTE FORCE
    // string ans= "";
    // int n= v.size();

    // for(int i=0;i<n;i++){
    //     bool flag = false;
    //     for(int j=0;j<n;j++){
    //         // if(flag) break;
    //         for(int k=0;k<n;k++){
    //             string x = v[j] + v[k];
    //             if(v[i].compare(x)==0){
    //                 flag = true;
    //                 goto label;
    //                 break;
    //             }
    //         }
    //     }
    //    label: if(flag){
    //         ans+= "1";
    //     }else{
    //         ans+="0";
    //     }
    // }
    // cout<< ans << endl;

    //NEVER USE SET OR MAP for taking input if order of input is important

    unordered_set<string> v;

    int n= arr.size();
    for(int i=0;i<n;i++){
        v.insert(arr[i]);
    }
    string ans ="";
    for(int i=0;i<n;i++){
        string s =arr[i];
        bool flag=false;
        for(int j=1;j<s.size();j++){
            string a =s.substr(0,j);
            string b = s.substr(j,s.size()-j);
            if(v.find(a) !=v.end() && v.find(b)!=v.end()){
                flag = true;
                break;
            }

        }
    

        if(flag==true){
            ans+="1";
        }else{
            ans+="0";
        }
    }
    cout<< ans<< endl;

}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<string> v;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            v.push_back(x);
        }
        solve(v);
    }

}