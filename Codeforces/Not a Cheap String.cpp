#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*
Let s be a string of lowercase Latin letters. Its price is the sum of the indices of letters (an integer between 1 and 26) that are included in it. For example, the price of the string abca is 1+2+3+1=7.
The string w and the integer p are given. Remove the minimal number of letters from w so that its price becomes less than or equal to p and print the resulting string. Note that the resulting string may be empty. You can delete arbitrary letters, they do not have to go in a row. If the price of a given string w is less than or equal to p, then nothing needs to be deleted and w must be output.
Note that when you delete a letter from w, the order of the remaining letters is preserved. For example, if you delete the letter e from the string test, you get tst.


Input
The first line of input contains an integer t (1≤t≤104) — the number of test cases in the test. The following are descriptions of t test cases.
Each case consists of two lines.
The first of them is the string w, it is non-empty and consists of lowercase Latin letters. Its length does not exceed 2⋅105.
The second line contains an integer p (1≤p≤5200000).
It is guaranteed that the sum of string lengths w over all test cases does not exceed 2⋅105.

Output
Output exactly t rows, the i-th of them should contain the answer to the i-th set of input data. Print the longest string that is obtained from w by deleting letters such that its price is less or equal to p. If there are several answers, then output any of them.
Note that the empty string  — is one of the possible answers. In this case, just output an empty string


Example:
input : 
5
abca
2
abca
6
codeforces
1
codeforces
10
codeforces
100
----------------------
ouput:
aa
aba

cdc
codeforces

*/

void solve(string s, int p){
    map<int, vector<int>> m;
    map<int, vector<int>> ans;
    int sum =0;
    int n= s.size();
    for(int i=0;i<s.size();i++){
        sum += s.at(i) -'a' +1;
        if(m.find(s.at(i) -'a' +1) !=m.end()){
            auto it = m.find(s.at(i)-'a' +1);
            (*it).second.push_back(i);
        }else{
            vector<int> v;
            v.push_back(i);
            m[s.at(i)-'a' +1] = v;
        }
    }
    if(sum <=p){
        cout<< s<< endl;
        return;
    }

    auto it = m.end();
    it--;
    while(sum>p){
        for(int i=0;i<(*it).second.size();i++){
            //replace the removed characters with '.' to distinguish
            s[(*it).second[i]] = '.';
            sum -= (*it).first;
            if(sum<=p) break;
        }
        it--;
    }


    for(int i=0;i<s.size();i++){
        if(s.at(i)!='.'){
            cout<<s[i];
        }
    }
        cout<< endl;


}




int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string x; int p;
        cin>> x>>p;
        solve(x,p);
    }

}