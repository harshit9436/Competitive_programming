#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string longestCommonPrefix(vector<string>& strs) {
    string ans ="";
    // sort(strs.begin(),strs.end(),compare);
    int mini=INT_MAX;
    for(int i=0;i<strs.size();i++){
        mini = (mini>strs[i].size()) ? strs[i].size(): mini;
    }
    for(int i=0;i<mini;i++){
        bool a= true;
        char x = strs[0][i];
        for(int j=1;j<strs.size();j++){
            if(x!=strs[j][i]){
                a = false;
                break;
                }
            }
        if(a){
            ans +=strs[0][i];
        }else{
            break;
        }
    }
    return ans;
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> v = {"flower","flow","flight"};
    cout << longestCommonPrefix(v);
}