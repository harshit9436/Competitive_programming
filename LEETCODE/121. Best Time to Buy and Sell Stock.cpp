//link https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n= prices.size();
        int x =  prices[n-1];
        for(int i=n-2;i>=0;i--){
            x = max(x,prices[i]);
            ans = max(ans,x-prices[i]);
        }
        return ans;
    }
};
