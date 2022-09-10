#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void add(vector<int> &v,int k, vector<int> temp){
    int c=0, s=0;
    // vector<int> temp = v;
    for(int j=0;j<k;j++){
        for(int i =v.size()-1;i>=0;i--){
            s = (v[i] + temp[i]+c) %10;
            c = (v[i]+temp[i]) /10;
            v[i] = s;
        }
        if(c==1){
            v.insert( v.begin(),c);
        }

    //     for(int i=0;i<v.size();i++){
    //     cout << v[i] <<" ";
    // }cout<< endl;
    }
    
    
    // return v;
}

vector<int> factorial(int N){
    // code here
    vector<vector<int>> dp;
    dp.push_back({1}); //0!
    dp.push_back({1}); //1!
    dp.push_back({2}); //1!
    dp.push_back({6}); //1!
    dp.push_back({2,4}); //1!
    for(int i=5;i<=N;i++){
        vector<int> v = dp[i-1];
        add(v,i-1, dp[i-1]);
        dp.push_back(v);

    //     for(int i=0;i<v.size();i++){
    //     cout << v[i] <<" ";
    // }
    // cout<<endl;
    }

     

    return dp[N];
}

int main(){
    // vector<int> v = {1,2 };
    // vector<int> x =v;
    // add(v,3, x);
    vector<int> v = factorial(5);
    // add(v);

    for(int i=0;i<v.size();i++){
        cout << v[i] <<" ";
    }
}