// link https://leetcode.com/problems/generate-parentheses/

// add "()" to all the possible valis parenthesis of size n-1, use set to avoid repititions
class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        map<int,unordered_set<string>> map;
        map[1].insert("()")

        for(int i=2;i<=n;i++){
            for(auto it =  map[i-1].begin();it !=  map[i-1].end();it++){
                for(int j=0;j<(*it).length();j++){
                    map[i].insert((*it).substr(0,j+1) + "()" + (*it).substr(j+1, ((*it).size()-j-1)));
                }
            }
        }

        vector<string> arr;
         for(auto it = map[n].begin();it != map[n].end();it++){
        arr.push_back((*it));
    }
        return arr;
    }
};