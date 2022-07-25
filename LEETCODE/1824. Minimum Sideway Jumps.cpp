//link https://leetcode.com/problems/minimum-sideway-jumps/

//very bad coding but beats 97%
//logic iscorrect and similar to obstacle in a 2d array
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int dp[3][n];
        dp[0][n-1] =0, dp[1][n-1]=0, dp[2][n-1]=0;
        for(int i=0;i<n;i++){
            if (obstacles[i] !=0){
            dp[obstacles[i]-1][i] =INT_MAX; 
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(obstacles[i+1]==1){
                dp[1][i] = dp[1][i+1];
                dp[2][i] =  dp[2][i+1];
                if(obstacles[i]!=0){
                dp[obstacles[i]-1][i] = INT_MAX;
                }
                dp[0][i] = 1+min(dp[1][i], dp[2][i]);
            }
            if(obstacles[i+1]==2){
               dp[0][i] = dp[0][i+1];
                dp[2][i] =  dp[2][i+1];
                if(obstacles[i]!=0){
                dp[obstacles[i]-1][i] = INT_MAX;
                }
                if(i==1){
                    cout<< "djhd" << dp[0][i+1] << dp[2][i+1]<< endl;
                }
                dp[1][i] = 1+min(dp[0][i], dp[2][i]);
            }
            if(obstacles[i+1]==3){
                dp[1][i] = dp[1][i+1];
                dp[0][i] =  dp[0][i+1];
                if(obstacles[i]!=0){
                dp[obstacles[i]-1][i] = INT_MAX;
                }
                dp[2][i] = 1+min(dp[1][i], dp[0][i]);
            }
            if(obstacles[i+1]==0){
                dp[0][i] = dp[0][i+1];
                dp[1][i]=dp[1][i+1];
                dp[2][i] =dp[2][i+1];
                if(obstacles[i]!=0){
                dp[obstacles[i]-1][i] = INT_MAX;
                }
            }
            
        }

        return dp[1][0];
    }
};