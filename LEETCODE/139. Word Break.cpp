//link https://leetcode.com/problems/word-break/

// Take dict[i] if possible and check by both taking it and ignoring it
// Important question, see video for solution
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size()+1];
        for(int i=0;i<s.size();i++) dp[i]=false;
        dp[s.size()] = true;
        
        for(int i=s.size()-1;i>=0;i--){
            for(string x : wordDict){
                if(((i+x.size() ) <=s.size()) && s.substr(i,x.size())== x){
                    dp[i] = dp[i+x.size()];
                    if(dp[i]) break;
                }
            }
        }
        
        return dp[0];
    }
};