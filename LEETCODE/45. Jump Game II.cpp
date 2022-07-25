// link https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        // O(N^2)
        int n= nums.size();
        long dp[n];
        for(int i=0;i<n;i++) dp[i] =INT_MAX;
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            // int x = nums[i];
            long a = INT_MAX;
            for(int j=i; j<= min(i+nums[i],n-1);j++){
                a = min(a,dp[j]);
            }
            dp[i] = 1+ a;
        }
        
        return dp[0];
        
        // O(N)
        int jumps =0, begin=0 , end=0, farthest=0;
            for(int i=0;i<nums.size()-1 ;i++){
                farthest = max(farthest,i+nums[i]);                
                if(i==end){
                    end =farthest;
                    jumps++;
                }
                
                
            }
        return jumps;
        
    }
};