//link https://leetcode.com/problems/minimum-cost-for-tickets/

// check which tickets would reduce expense at each step, basically counting number of days in the range and their cost
class Solution {
public:
    int solve(int * days, int *cost, int n, int * dp){
        if(n <= 0) return 0 ;
        
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        int up1 = upper_bound(days,days+n,days[0]+1-1) - days;
        int up2 = upper_bound(days,days+n,days[0]+7-1) -days;
        int up3 = upper_bound(days,days+n,days[0]+30-1) -days;
        
        ans = min(cost[0]+ solve(days+1,cost,n-1, dp), 
        min(cost[1]+ solve(days+up2,cost,n-up2,dp), cost[2]+ solve(days+up3,cost,n-up3,dp)));
        dp[n] = ans;
        return ans;
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int day[n]; int cost[3];
        for(int i=0;i<n;i++){
            day[i]=days[i];
        }
        cost[0]= costs[0];
        cost[1]= costs[1];
        cost[2]= costs[2];
        
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i] =-1;
        
        
        return solve(day,cost,n,dp);
    }

};