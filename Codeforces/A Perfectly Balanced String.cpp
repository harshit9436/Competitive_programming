#include <iostream>
using namespace std;
#include <bits/stdc++.h>


/*


Let's call a string s perfectly balanced if for all possible triplets (t,u,v) such that t is a non-empty substring of s and u and v are characters present in s, the difference between the frequencies of u and v in t is not more than 1.
For example, the strings "aba" and "abc" are perfectly balanced but "abb" is not because for the triplet ("bb",'a','b'), the condition is not satisfied.
You are given a string s consisting of lowercase English letters only. Your task is to determine whether s is perfectly balanced or not.
A string b is called a substring of another string a if b can be obtained by deleting some characters (possibly 0) from the start and some characters (possibly 0) from the end of a.

Input
The first line of input contains a single integer t (1≤t≤2⋅104) denoting the number of testcases.
Each of the next t lines contain a single string s (1≤|s|≤2⋅105), consisting of lowercase English letters.
It is guaranteed that the sum of |s| over all testcases does not exceed 2⋅105.

Output
For each test case, print "YES" if s is a perfectly balanced string, and "NO" otherwise.
You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

*/

//LET THERE BE K distinct characters in the string then any substring of size k must contain all distinct characters (O(n.mlog(m)))



void solve(string s){
    map<char, int> v;
    int cnt =0;
    for(int i=0;i<s.size();i++){
         if(v.find(s[i])!=v.end()){
                v[s[i]]++;
            }else{
                v.insert(make_pair(s[i],1));
                cnt++;
            }
    }

    for(int i=0;i<s.size()-cnt +1 ;i++){
        map<int,char> mp;
        for(int j=i;j<i+cnt;j++){
            if(mp.find(s[j])!=mp.end()){
                cout<<"NO"<<endl;
                return;
            }else{
                mp.insert(make_pair(s[j],1));
            }
        }
         
    }
    cout<<"YES"<<endl;
}






int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        solve(s);
    }
}