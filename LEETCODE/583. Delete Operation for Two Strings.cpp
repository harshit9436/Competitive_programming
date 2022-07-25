//link https://leetcode.com/problems/delete-operation-for-two-strings/

// using concept of edit distance
class Solution {
public:
    
    
int editI(char* s1, char* s2, int m, int n){

    int** dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]= new int[n+1];
    }

for(int i=0;i<=m;i++) dp[i][0]=i;
for(int i=0;i<=n;i++) dp[0][i]=i;


for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s1[m-i]==s2[n-j]){
           dp[i][j]= dp[i-1][j-1];
        }else{
            dp[i][j]= 1+ min(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int ans = dp[m][n];
for(int i = 0; i<=m;i++){
    delete[] dp[i];
}
delete[] dp;
return ans;

}
    
    
    
    
    
    int minDistance(string text1, string text2) {
         int m = text1.length();
        int n= text2.length();
        char s1[1024] ; char s2[1024]; 
        strcpy(s1, text1.c_str());
        strcpy(s2, text2.c_str());

        return editI(s1,s2,m,n);
        
    }
    
    
};