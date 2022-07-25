//link  https://leetcode.com/problems/longest-palindromic-substring/


//basic approach
//better solution using expand from center and using len to find start and end index
class Solution {
public:
pair<int,int> solve(string s , int i, int j){
    int n= s.size();
    while(i>=0 and j<n){
        if(s[i]==s[j]){
             i--;j++;
        }else{
            pair<int,int> p = make_pair(i,j);
            return p;
        }
    }
    pair<int,int> p = make_pair(i,j);
    return p;
}
    
    string longestPalindrome(string s) {
      int n = s.size();
    pair<int,int> ans = make_pair(0,0);
    for(int i=0;i< n;i++){
        pair<int,int> a = solve(s,i,i);
        pair<int,int> b = solve(s,i,i+1);
        pair<int,int> x = ((a.second-a.first) > (b.second-b.first)) ? a : b;
        ans = ((ans.second-ans.first) > (x.second-x.first)) ? ans : x;
    }
    return s.substr(ans.first+1,(ans.second-ans.first-1));
    }
};