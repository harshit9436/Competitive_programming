#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool com(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    vector<pair<int,int>> v;
    v.push_back({1,2});
    v.push_back({1,1});
    v.push_back({2,2});
    v.push_back({5,4});
    v.push_back({0,10});

    sort(v.begin(),v.end(),com);

    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " <<v[i].second <<endl;
    }


}