#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*


A class of students got bored wearing the same pair of shoes every day, so they decided to shuffle their shoes among themselves. In this problem, a pair of shoes is inseparable and is considered as a single object.
There are n students in the class, and you are given an array s in non-decreasing order, where si is the shoe size of the i-th student. A shuffling of shoes is valid only if no student gets their own shoes and if every student gets shoes of size greater than or equal to their size.
You have to output a permutation p of {1,2,…,n} denoting a valid shuffling of shoes, where the i-th student gets the shoes of the pi-th student (pi≠i). And output −1 if a valid shuffling does not exist.
A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤105) — the number of students.
The second line of each test case contains n integers s1,s2,…,sn (1≤si≤109, and for all 1≤i<n, si≤si+1) — the shoe sizes of the students.
It is guaranteed that the sum of n over all test cases does not exceed 105.


Output
For each test case, print the answer in a single line using the following format.
If a valid shuffling does not exist, print the number −1 as the answer.
If a valid shuffling exists, print n space-separated integers — a permutation p of 1,2,…,n denoting a valid shuffling of shoes where the i-th student gets the shoes of the pi-th student. If there are multiple answers, then print any of them.

*/





void solve(vector<int> &v){
    map<int,vector<int>> mp;
    for(int i=0;i<v.size();i++){
        if(mp.find(v[i])!=mp.end()){
            mp[v[i]].push_back(i+1);
        }else{
            vector<int> a;
            a.push_back(i+1);
            mp.insert(make_pair(v[i],a));
        }
    }
    bool poss = true;
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        if((*it).second.size()==1){
            cout<< -1 <<endl;
            return;
        }else{
            vector<int> x = (*it).second;
            ans.push_back(x[x.size()-1]);
            for(int j=0;j<x.size()-1;j++){
                ans.push_back(x[j]);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }
    cout<<endl;
}



int main(){

#ifndef ONLINE_JUDGE
    freopen("zinput.txt" , "r" , stdin);
    freopen("zoutput.txt" , "w" , stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        solve(v);
    }

}