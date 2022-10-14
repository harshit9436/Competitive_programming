#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(vector<vector<int> > matrix, int a, int b, int c, int d, vector<int> &ans){
        if(a>=b || c>=d){
            return;
        }
        for(int i=c;i<=d;i++){
            ans.push_back(matrix[a][i]);
        }
        a++;
        for(int i=a;i<=b;i++){
            ans.push_back(matrix[i][d]);
        }
        d--;
        if(a>b || c>d){
            return;
        }

        for(int i=d;i>=c;i--){
            ans.push_back(matrix[b][i]);
        }
        b--;

        for(int i=b;i>=a;i--){
            ans.push_back(matrix[i][c]);
        }
        c++;
        solve(matrix,a,b,c,d,ans);

}


void spirallyTraverse(vector<vector<int> > matrix, int m, int n) 
{
    vector<int> ans;
    int a = 0, b = m-1, c =0 , d=n-1;
    solve(matrix,a,b,c,d,ans);
    // while(a<b && c<d){
        
    // } 

    // while(a<b){
    //     ans.push_back(matrix[a][c]);
    //     a++;
    // }
    // while(c<=d){
    //     ans.push_back(matrix[a][c]);
    //     c++;
    // }

    for(int i=0;i<ans.size();i++){
        cout<< ans[i]<< " ";
    }

    // return ans;

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int r,c;
    cin >> r>>c;
    vector<vector<int>> v (r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            v[i][j]=x;
        }
    }
    spirallyTraverse(v,r,c);
}