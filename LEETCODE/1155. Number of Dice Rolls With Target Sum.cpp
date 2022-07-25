//link https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// at each step we have k choices
class Solution {
public:
     const int mod = 1e9+7;
    int solve(int n, int k, int target, int** dp){
        // int mod=1000000007;
       if(n==0 & target==0) return 1;
        if(n==0 || target<=0) return 0;
        if (dp[n][target] !=-1) return dp[n][target]%mod ; 
        int ans =0;
        for(int i=1;i<=k;i++){
            ans += solve(n-1,k,target-i, dp);
            ans = ans%mod;
        }
        dp[n][target] = ans%mod ;
        return dp[n][target];
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        int ** dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]= new int[target+1];
            for(int j=0;j<=target;j++){
                dp[i][j] =-1;
            }
        }
        
        int ans = solve(n,k,target,dp);
        for(int i=0;i<=n;i++){
            delete[] dp[i];
        }
        delete[] dp;
        
        return ans;
        
        
    }
};