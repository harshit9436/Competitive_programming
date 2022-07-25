//link https://leetcode.com/problems/longest-arithmetic-subsequence/

//using concept of longest AP with fixed commmon diff
class Solution {
public:
    int dp[501];
    int longestArithSeqLength(vector<int>& nums) {
        int best_ans = 1;
        
        for (int diff = -500; diff < 501; ++diff) {
            memset(dp,0,sizeof(dp));
            for (int num: nums) {
                if (num - diff >= 0 && num-diff <= 500) {
                    dp[num] = max(dp[num],dp[num-diff]+1);
                    best_ans = max(dp[num],best_ans);
                } else {
                    dp[num] = 1;
                }
            }
        }
        return best_ans;
        
    }
};