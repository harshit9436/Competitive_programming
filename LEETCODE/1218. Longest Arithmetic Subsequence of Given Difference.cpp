//link https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
//         int n = arr.size();
//         int dp[n];
//         int ans = 1;
//         for(int i=0;i<n;i++){
//             int len =1;
//             for(int j=i-1;j>=0;j--){
//                 if(arr[j] == arr[i]-difference){
//                     len = max(len,1+dp[j]);
//                     ans = max(ans,len);
//                 }
//             }
//             dp[i] = len;
//         }
        
//         return ans;
        
        
        int n = arr.size();
        unordered_map<int,int> dp;
        int ans = 1;
        for(int i=0;i<n;i++){
            if (dp.find(arr[i]-diff) !=dp.end()){
                dp[arr[i]] = 1+ dp[arr[i]-diff];
                ans = max(ans,dp[arr[i]]);
            }else{
                dp[arr[i]] =1;
            }
        }
        
        return ans;
    }
};