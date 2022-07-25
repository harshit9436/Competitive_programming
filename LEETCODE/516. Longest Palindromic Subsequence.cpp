//link https://leetcode.com/problems/longest-palindromic-subsequence/

// longest common subseq in s1 and rev(s1)
class Solution {
public:
int lcs(char*s1, char*s2 ,  int m, int n, int** dp){
    if(m==0 || n==0){ return 0; }
    if(dp[m][n]>-1) return dp[m][n];
    int ans;
    if(s1[0]==s2[0]){ 
        ans = 1+lcs(s1+1,s2+1,m-1,n-1,dp);
    }else{ 
        ans = max(lcs(s1+1,s2,m-1,n,dp), lcs(s1,s2+1,m,n-1,dp));
    }
    return dp[m][n] = ans;
}    

    
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        char s1[n];
        char s2[n];
        for(int i=0;i<n;i++){
            s1[i] = s[i];
            s2[n-1-i] = s[i];
        }
        int ** dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }

    
        return lcs(s1,s2, n, n, dp);
        
    }
};