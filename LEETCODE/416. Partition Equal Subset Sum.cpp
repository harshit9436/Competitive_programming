//link https://leetcode.com/problems/partition-equal-subset-sum/

// similar to subset of array equal toa target, target - sum of araray /2;
class Solution {
public:
    
    bool solve(int* nums, int n, int target){        
         bool dp[n+1][target+1];

        for(int i=0;i<=target;i++) dp[0][i]=false;
        for(int i=0;i<=n;i++) dp[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target ;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][target];
        

        
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        int target=0;
        for(int i=0;i<n;i++){
            arr[i] = nums[i];
            target+=nums[i];
        }
        
        if (target%2 ==1) {return false;}
        else{
            target = target/2;
        return solve(arr,n,target);
            
        }
        
    }
};