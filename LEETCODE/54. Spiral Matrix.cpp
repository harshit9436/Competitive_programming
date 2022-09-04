#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//Using recurssion, just need to think about base case.
void print(vector<vector<int>>& matrix ,vector<int> &ans, int i, int j, int n, int m){

    if(i>=n || j>=m){
        return;
    }
    for(int a=j;a<m;a++){
        ans.push_back(matrix[i][a]);
    }
    
    for(int a=i+1;a<n;a++){
        ans.push_back(matrix[a][m-1]);
    }
    
    if(i!=n-1){
        for(int a = m-2;a>=j;a--){
            ans.push_back(matrix[n-1][a]);
        }
    }
    if(j!= m-1){
        for(int a=n-2;a>i;a--){
            ans.push_back(matrix[a][j]);
        }
    }
    print(matrix,ans,i+1,j+1,n-1,m-1);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    print(matrix,ans,0,0,matrix.size(),matrix[0].size());
    return ans;
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

