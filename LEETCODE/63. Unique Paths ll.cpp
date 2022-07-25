// link https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
// pretty simple lgic, cant edit dp[i][j] if it has obtacles and cant if dp[i][j] in both dp[i+1][j] and dp[i][j+1]
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        int dp[m][n];
        
        dp[0][0]= (grid[0][0]==0)? 1 :0;
        for(int i=1;i<m;i++){
            if(grid[i][0]==0){
                dp[i][0]= dp[i-1][0];
            }else{
                dp[i][0] = 0;
            }
        }
        
        for(int i=1;i<n;i++){
            if(grid[0][i]==0){
                dp[0][i]= dp[0][i-1];
            }else{
                dp[0][i] = 0;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] =0;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    dp[i][j] =0;
                }else{
                    if(grid[i-1][j] ==0){
                        dp[i][j] += dp[i-1][j];
                    }
                    if(grid[i][j-1] ==0){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};