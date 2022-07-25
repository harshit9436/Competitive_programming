//link https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //O(N^2)
//         int n = nums.size();
//         bool dp[n];
//         for(int i=0;i<n;i++) dp[i] =false;
//         dp[n-1] = true;
//         for(int i=n-2;i>=0;i--){
//             bool a= false;
//             for(int j=i; j<= min(i+nums[i],n-1);j++){
//                 a = a || dp[j];
//                 if(a){
//                     break;
//                 }
                    
//             }
//             dp[i] = a;
//         }
        
//         return dp[0];
        
        
    //O(N)
    int reachable = 0;
    for(int i=0;i<nums.size();i++){
        if(i>reachable) return false;
        reachable = max(reachable, i+nums[i]);
    }
    return true;

        
        
   
        
    }
};