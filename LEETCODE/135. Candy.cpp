//link https://leetcode.com/problems/candy/

// first solve from left to right and then from right to left
class Solution {
public:
    int candy(vector<int>& nums) {

    int dp[nums.size()];
    for(int i=0;i<nums.size();i++){
        dp[i]=INT_MAX;
    }
    dp[0]=1;
    for(int i=1; i<nums.size();i++){
        if(nums[i] >nums[i-1]){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=1;
        }
    }

    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]>nums[i+1]&& dp[i+1]>=dp[i]){
            dp[i]= dp[i+1]+1;
        }
    }
    int ans=0;
    for (int i=0;i<nums.size();i++){
        ans+=dp[i];
    }
 
    return ans;
        
    }
};