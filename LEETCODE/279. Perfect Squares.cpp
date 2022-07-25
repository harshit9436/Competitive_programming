// link https://leetcode.com/problems/perfect-squares/

// se some theroem stating it would need maximum of 4 numbers
class Solution {
public:
int solve(int n, int* dp){
    if(n==1) return 1;
    for(int i=1;i<=n;i++){
        int j=1;
        while(j*j<=i){
            dp[i] = min(dp[i], dp[i- j*j] + 1);
            j++;
        }
    }
    
    return dp[n];
    
}
    int numSquares(int n) {
        int arr[n+1];
        for(int i=0;i<=n;i++) arr[i]=INT_MAX;
        arr[0]=0;
        return solve(n, arr);
    }
};