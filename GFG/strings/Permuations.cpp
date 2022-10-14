#include <iostream>
using namespace std;
#include <bits/stdc++.h>


unordered_set<string> solve(string p, string up){
    if(up.size()==0){
        unordered_set<string> s; 
            s.insert(p);
        return s;
    }
    
    unordered_set<string> s;
    for(int i=0;i<=p.size();i++){
        string start = p.substr(0,i);
        string end = p.substr(i,p.size()-i);
        unordered_set<string> s1 = solve(start+up[0]+end , up.substr(1,up.size()-1)); 
        s.insert(s1.begin(),s1.end());
    }
    
    return s;
    
}

vector<string>find_permutation(string S){
    unordered_set<string> s = solve("", S);
    vector<string> ans; 
    for(auto it = s.begin(); it!=s.end();it++){
        ans.push_back((*it));
    }
    sort(ans.begin(),ans.end());
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