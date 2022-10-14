#include <iostream>
using namespace std;
#include <bits/stdc++.h>



 vector<string> solve(string p, string s){
    if(s.size()==0 ){
        vector<string> v;
        if(p.size()!=0){
        v.push_back(p);    
        }
        
        return v;
    }
    vector<string> v = solve(p+s[0], s.substr(1,s.size()-1));
    vector<string> v1 = solve(p, s.substr(1,s.size()-1));
    for(int i=0;i<v1.size();i++){
        v.push_back(v1[i]);
    }
    return v;

}
	
	
vector<string> AllPossibleStrings(string s){
    vector<string> ans = solve("", s);
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