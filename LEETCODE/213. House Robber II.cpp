//link https://leetcode.com/problems/house-robber-ii/

//either start from first till n-1 or from second till N, find max in both cases, ans = max of them
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[n+1];
        dp[0] = 0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        //dp[n-1];
        int a = dp[n-1];
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return max(a,dp[n]);
    }
};