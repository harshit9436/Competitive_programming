//link https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int m= grid.size() , n = grid[0].size();
        vector<vector<int> > cost(m, vector<int> (n,0));
        cout << cost.size() << " " << cost[0].size();
        cost[m-1][n-1] = grid[m-1][n-1];
        for(int i=n-2;i >=0;i--){
            cost[m-1][i] = grid[m-1][i] + cost[m-1][i+1];
        }
        for(int i= m-2;i>=0;i--){
            cost[i][n-1]= grid[i][n-1] + cost[i+1][n-1];
        }
        
        for(int i= m-2 ; i>=0 ;i--){
            for(int j= n-2; j>=0;j--){
                int x= cost[i+1][j] >cost[i][j+1] ? cost[i][j+1] : cost[i+1][j];
                cost[i][j] = x +grid[i][j];
            }
        }
        
        
         return cost[0][0];
 // return 0;
        
    }
};