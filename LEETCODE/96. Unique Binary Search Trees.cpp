//link https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    
    int solve(int n, int* dp){
        if(n<=1) return 1;
        int i=n, ans=0;
        if(dp[i]!=0)return dp[i];
while(i>=1){
        ans+= solve(n-i, dp)*solve(i-1, dp);
    i--;
        }        
        return dp[n]=ans;
    }
    
    int numTrees(int n) {
        int arr[n+1];
        for (int i=0;i<=n;i++) arr[i]=0;
        return solve(n,arr);   
    }
    
    
};