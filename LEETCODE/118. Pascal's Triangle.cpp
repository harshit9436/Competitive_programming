// link https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> dp(numRows, vector<int>());
        dp[0] = {1};

        
        for(int i=1;i<numRows ;i++){
            vector<int> prev = dp[i-1];
            vector<int> v;
            v.push_back(1);
            for(int i=1;i< prev.size();i++){
                v.push_back(prev[i]+prev[i-1]);
            }
            v.push_back(1);
            dp[i] = v;
        }
        return dp;
    }
};