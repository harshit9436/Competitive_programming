#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(string x){
    int space = x.find(" ");
    string left = x.substr(0,space);
    string right = x.substr(space+1, x.length()-1-space);
    // cout<< left << " jf" << right << endl;
    int i = 0;
    int j = 0;
    while(i < left.size() && j < right.size()){
        if(left[i]=='+'){
            j++;
            i++;
        }else if(left[i]=='*'){
            if(left[i+1]=='{'){
                int s = (x[i+2] -'0');
                j+=s;
                i+= 4;
            }else{
                j+=3;
                i++;
            }
        }
    }
    if(i==left.size() && j==right.size()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string x;
    getline(cin,x);
    // cout<< x << endl;
    solve(x);
}