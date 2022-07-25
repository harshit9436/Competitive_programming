//link https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    
int solve(int amount, vector<int> coins ,int size, vector< vector<int> > &arr) {
    
    if(amount==0) return 1;
    if(amount<0 || size==0) return 0;
    if(arr[amount][size]!=-1) return arr[amount][size];
    int output = solve(amount-coins[size-1],coins,size, arr) + solve(amount,coins,size-1, arr);
    return arr[amount][size]=output;
    
    }

int change(int amount, vector<int>& coins) {
    vector< vector<int> > arr(amount+1,vector<int>( coins.size()+1,-1));
        return solve(amount,coins,coins.size(),arr);
    }

};