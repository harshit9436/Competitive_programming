
//link https://leetcode.com/problems/interleaving-string/

//dp[i][j] stores if using s1(0:i) and s2(0:j) making s3(0:i+j) is possible
class Solution {
public:
    bool solve(string s1, string s2, string s3){
        
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size()){
            return false;
        }
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        
        for(int i=1;i<=n;i++) dp[0][i] = (dp[0][i-1] && s2[i-1] == s3[i-1]);
        for(int i=1;i<=m;i++) dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
        
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
                dp[i][j]=(dp[i-1][j]&&(s1[i-1]==s3[i+j-1])) || (dp[i][j-1]&&(s2[j-1]==s3[i+j-1]));

        return dp[m][n];
    }
        
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1,s2,s3);
    }
};