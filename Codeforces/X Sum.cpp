#include <iostream>
using namespace std;
#include <bits/stdc++.h>


/*
Timur's grandfather gifted him a chessboard to practice his chess skills. This chessboard is a grid a with n rows and m columns with each cell having a non-negative integer written on it.
Timur's challenge is to place a bishop on the board such that the sum of all cells attacked by the bishop is maximal. 
The bishop attacks in all directions diagonally, and there is no limit to the distance which the bishop can attack. Note that the cell on which the bishop is placed is also considered attacked. Help him find the maximal sum he can get.


Input
The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. The description of test cases follows.
The first line of each test case contains the integers n and m (1≤n≤200, 1≤m≤200).
The following n lines contain m integers each, the j-th element of the i-th line aij is the number written in the j-th cell of the i-th row (0≤aij≤106)
It is guaranteed that the sum of n⋅m over all test cases does not exceed 4⋅104.

Output
For each test case output a single integer, the maximum sum over all possible placements of the bishop.


*/







void solve(vector<vector<int>> v){
    int ans=INT_MIN;
    int n =v.size();
    int m = v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int maxi = v[i][j];
            int l =i , k =j;
            while(l>=0 && k>=0){
                maxi+=v[l][k];
                l--;k--;
            }
            // cout<< maxi <<" ";
            l=i;k=j;
            while(l<=n-1 && k>=0){
                maxi+=v[l][k];
                l++;k--;
            }
            // cout<< maxi <<" ";

            l=i;k=j;
            while(l<=n-1 && k<=m-1){
                maxi+=v[l][k];
                l++;k++;
            }
            // cout<< maxi <<" ";

            l=i;k=j;
            while(l>=0 && k<=m-1){
                maxi+=v[l][k];
                l--;k++;
            }
            // cout<< maxi <<" ";
            maxi = maxi - 4*v[i][j];
            ans = max(ans,maxi);
            // cout<<maxi <<endl;

        }
    }
    cout<< ans<<endl;
}





int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>> t;
    while(t--){
        int m, n;
        cin >>n>>m;
        vector<vector<int>> candies(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k;
                cin >>k;
                candies[i][j] = k;
            }
        }
        solve(candies);
        // for(int i=0;i<n;i++){
        // for(int j=0;j<m;j++){
        //     cout<< candies[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }


}