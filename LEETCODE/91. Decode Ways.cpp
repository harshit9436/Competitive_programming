//link https://leetcode.com/problems/decode-ways/

class Solution {
public:
    
 // for every '0' in the senetence it should always be paired with char before it i.e if pairing is possible.
// using simple conditions to tackle the these situations
int solve(char* s1, int n){
    int dp[n+1];
    if(s1[0]=='0'){
        return 0;
    } else{
        dp[0]=1;
        dp[1]=1;
    }
    if(n<=1) return 1;
    
    
    for(int i=2;i<=n;i++){
        if(s1[i-1] == '0' ){
            if( (((s1[i-2]-'0')*10 + s1[i-1] - '0') <=26) && 
               (((s1[i-2]-'0')*10 + s1[i-1] - '0') >0)){   
                dp[i] = dp[i-2];    
                continue;
            }else{
            cout<<"fff" << i;
            dp[i] = 0;
            return 0;      
            }
        }
        
        dp[i] = dp[i-1];
        
        if((s1[i-2]!='0' &&  (((s1[i-2]-'0')*10 + s1[i-1] - '0') <=26) && 
           (((s1[i-2]-'0')*10 + s1[i-1] - '0') >0))){
            dp[i] += dp[i-2];
        }
    
    }

    return dp[n];
    
}

int numDecodings(string s) {

    
    int n = s.size();
    char s1[n] ;

    for(int i=0;i<n;i++) {
        s1[i] = s[i];
    }
        
    return solve(s1,n);
}

};