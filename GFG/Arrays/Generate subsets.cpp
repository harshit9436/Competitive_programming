#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void dfs(vector<int> &nums, int i, vector<int> &v, vector<vector<int>> &ans){
    
    if(v.size()==nums.size()){
        ans.push_back(v);
        return;
    }
    for(int i=0;i<nums.size();i++){
        vector<int> subset;
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,ans);
        subset.pop_back();
        dfs(nums,i+1,subset,ans);   
    }

}

void subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> v;
    dfs(nums,0,v,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<< ans[i][j]<< " ";
        }
        cout<<endl;
    }
    // return ans;


}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    subsets(v);
}