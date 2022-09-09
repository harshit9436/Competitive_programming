#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//link https://leetcode.com/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int n= intervals.size();
    int j=0;
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=ans[j][1]){
            ans[j][1] = max( intervals[i][1], ans[j][1]);
        }else{
            ans.push_back(intervals[i]);
            j++;
        }
    }
    return ans;
}
int main(){

}