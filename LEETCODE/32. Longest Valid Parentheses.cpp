//link https://leetcode.com/problems/longest-valid-parentheses/

//store the index of last possible starting of valid substring
//see solution
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    int len = i - stk.top();
                    ans = max(ans,len);
                }
            }
        }
    
        
    return ans;
    }
};