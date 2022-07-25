//link https://leetcode.com/problems/distinct-subsequences/


// if character matches check by both moving forward in both string and just by moving in s1
//Nice question
class Solution {
public:
    // int mod = 1000000007;
    int solve(int i, int j, string &s, string &t,  vector<vector<int>> &dp){
        //BASE CASE
        if(j>=t.size() ) return 1;
        if(i>=s.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j] =  solve(i+1,j,s,t,dp) + solve(i+1,j+1,s,t,dp);
        }else{
            return dp[i][j] = solve(i+1,j,s,t,dp);
        }

        
    }
    
    int numDistinct(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
    }
};