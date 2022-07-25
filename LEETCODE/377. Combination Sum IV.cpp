//link https://leetcode.com/problems/combination-sum-iv/

// nums.size() number of choices at each step
class Solution {
public:
    
    int solve(int* nums, int n, int target, int * dp){
        if (target==0) return 1;
        if (n==0) return 0;
        if (dp[target]!=-1) return dp[target];
        
        int ans=0;
        for(int i=0;i<n;i++){
             if(nums[i]<=target){
            ans += solve(nums,n,target-nums[i],dp) ;
        
             }
        }
       
        return dp[target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i] = nums[i]; 
        }
        int dp[target+1];
        for(int i=0 ;i<=target;i++) dp[i] =-1;
        return solve(arr,n,target,dp);
    }
};