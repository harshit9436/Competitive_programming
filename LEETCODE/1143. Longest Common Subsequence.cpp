//link https://leetcode.com/problems/longest-common-subsequence/


//RECCURSSIVE
int solve(char* s1, char* s2){
    if(s1[0]=='\0' || s2[0]=='\0'){
        return 0;
    }

    if(s1[0]==s2[0]){
        return 1+solve(s1+1, s2+1);
    }else{
        return max(solve(s1+1,s2), solve(s1,s2+1));
    }

}

//DP
int lcsDP(char*s1, char* s2, int m , int n , int** dp){
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]>=0) return dp[m][n];
    int ans=0;
    if(s1[0]==s2[0]){
        // cout<<"djdjd";
        ans= 1+lcsDP(s1+1, s2+1, m-1,n-1,dp);
    }else{
        ans=  max(lcsDP(s1+1,s2, m-1,n,dp), lcsDP(s1,s2+1, m, n-1,dp));
    }
    dp[m][n] = ans;
    return ans;

}


int lcs(char*s1, char* s2, int m , int n){
    int ** dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            dp[i][j]=-1;
        }
    }
    int ans = lcsDP(s1, s2, m , n , dp);
    for(int i=0;i<m+1;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}


//Iterative
int LCSI(char*s1, char* s2, int m , int n){
 int ** dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            dp[i][j]=-1;
        }
    }

for(int i=0; i<=n; i++) dp[0][i]=0;
for(int i=0;i<=m;i++) dp[i][0]=0; 

for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s1[m-i]==s2[n-j]){
            dp[i][j]= 1+dp[i-1][j-1];
        }else{
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

return dp[m][n];

}



int main(){

char s1[100] = "abcde";
char s2[100] = "ace";
 cout<< LCSI(s1,s2, 5, 3);
// cout<< s1[0]<< endl;

}