// link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
//Divide and conquer , Nice question
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
        int left[n];
        int right[n];
        left[0]=0; right[n-1]=0;
        
        int buy1=prices[0];
        int sell2 = prices[n-1];
        
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], prices[i]-buy1);
            buy1 = min(buy1,prices[i]);
        }
        for(int i = n-2;i>=0;i--){
            right[i] =max(right[i+1],sell2-prices[i]);
            sell2 = max(sell2, prices[i]);
        }
        
        int ans = right[0];
        for(int i=0;i<n-1;i++){
            ans = max(ans,right[i+1]+left[i]);
        }
        ans=max(ans,left[n-1]);
        return ans;
    }
    
    
    //optimal solution, Not uderstood
//         int maxProfit(vector<int>& prices) {
//         int fb = INT_MIN,sb = INT_MIN;
//         int fs = 0,ss = 0;
//         for(auto x : prices){
//             fb = max(fb,-x);
//             fs = max(fs,fb+x);
//             sb = max(sb,fs-x);
//             ss = max(ss,sb+x);
//         }
//         return ss;
//     }
    
    
};

