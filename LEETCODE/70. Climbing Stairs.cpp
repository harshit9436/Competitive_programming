// link https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    
    int solve(int n, int* arr){
        arr[0]=1 ,arr[1]=1;
        for(int i=2;i<=n;i++){
            arr[i]= arr[i-1]+arr[i-2];
        }

        return arr[n];
    }


    
    int climbStairs(int n) {
        int arr[n+1];
        for(int i=0;i< n+1;i++){
            arr[i]=0;
        }
        return solve(n, arr);
        
    }
};