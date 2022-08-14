#include <iostream>
using namespace std;
#include <bits/stdc++.h>


/*

Timur has n candies. The i-th candy has a quantity of sugar equal to ai. So, by eating the i-th candy, Timur consumes a quantity of sugar equal to ai.
Timur will ask you q queries regarding his candies. For the j-th query you have to answer what is the minimum number of candies he needs to eat in order to reach a quantity of sugar greater than or equal to xj or print -1 if it's not possible to obtain such a quantity. 
In other words, you should print the minimum possible k such that after eating k candies, 
Timur consumes a quantity of sugar of at least xj or say that no possible k exists.
Note that he can't eat the same candy twice and queries are independent of each other (Timur can use the same candy in different queries).

Input
The first line of input contains a single integer t (1≤t≤1000)  — the number of test cases. The description of test cases follows.
The first line contains 2 integers n and q (1≤n,q≤1.5⋅105) — the number of candies Timur has and the number of queries you have to print an answer for respectively.
The second line contains n integers a1,a2,…,an (1≤ai≤104) — the quantity of sugar in each of the candies respectively.
Then q lines follow.
Each of the next q lines contains a single integer xj (1≤xj≤2⋅109) – the quantity Timur wants to reach for the given query.
It is guaranteed that the sum of n and the sum of q over all test cases do not exceed 1.5⋅105.

Output
For each test case output q lines. For the j-th line output the number of candies Timur needs to eat in order to reach a quantity of sugar greater than or equal to xj or print -1 if it's not possible to obtain such a quantity.


*/




void solve(vector<int> &cand, vector<int> &q){
    vector<int> sum;
    int s=0;
    sort(cand.begin(),cand.end());
    reverse(cand.begin(),cand.end());
    for(int i=0;i<cand.size();i++){
        s += cand[i];
        sum.push_back(s);
    }
    
    for(int i=0;i<q.size();i++){
        int k = lower_bound(sum.begin(),sum.end(),q[i]) - sum.begin();
        if(k== sum.size()){
            cout<< -1 <<endl;
        }else{
            cout << k+1<<endl;
        }

    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("zinput.txt" , "r" , stdin);
    freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>> t;
    while(t--){
        int n, q;
        cin >>n>>q;
        vector<int> candies(n,0), query(q,0);
        for(int i=0;i<n;i++){
            int k;
            cin >>k;
            candies[i] = k;
        }
        for(int i=0;i<q;i++){
            int k;
            cin >>k;
            query[i] = k;
        }

        // for(int i=0;i<n;i++){
        //     cout<< candies[i] << " ";
        // }cout << endl;


        solve(candies,query);
    }
}