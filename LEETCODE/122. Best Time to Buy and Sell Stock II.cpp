///link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
// sell immediately if prog=fit is possible
    int solve(vector<int>& prices){
        int ans=0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++){
            buy = min(buy,prices[i]);
            
            if(prices[i]>buy){
                ans +=prices[i]-buy;
                buy = prices[i];
            }
        }
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        return solve(prices);
        
    }
};