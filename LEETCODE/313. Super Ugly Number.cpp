//link https://leetcode.com/problems/super-ugly-number/

//used concept of first n numbers with 3 primes
//pointers to store the multiplicant of each prime
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      long long int dp[n];
        dp[0]=1;
        vector<int> pointer(primes.size(),0);
        for(int i=1;i<n;i++){
            long long int a=INT_MAX;
            for(int j=0;j<primes.size();j++){
                a = min(a,(dp[pointer[j]]*primes[j]));
            }
            for(int j=0;j<primes.size();j++){
                if(a==dp[pointer[j]]*primes[j]) {
                    pointer[j]++;
                    // cout << pointer[j]<< " ";
                }
            }
            dp[i]=a;
        }

        return dp[n-1];
    }
};