#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*


You have a stripe of checkered paper of length n. Each cell is either white or black.
What is the minimum number of cells that must be recolored from white to black in order to have a segment of k consecutive black cells on the stripe?
If the input data is such that a segment of k consecutive black cells already exists, then print 0.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.
Next, descriptions of t test cases follow.
The first line of the input contains two integers n and k (1≤k≤n≤2⋅105). The second line consists of the letters 'W' (white) and 'B' (black). The line length is n.
It is guaranteed that the sum of values n does not exceed 2⋅105.

Output
For each of t test cases print an integer — the minimum number of cells that need to be repainted from white to black in order to have a segment of k consecutive black cells.

*/



void solve(string s, int n, int k){
    // brute force will be O(N^2)
    

    //O(N)

    int mini=INT_MAX;
    int cnt =0;
     for(int j=0;j<k;j++){
        if(s[j] =='W'){
            cnt++;
        }
    }
    mini = min(mini,cnt);
    for(int i=k;i<n;i++){
        if(s[i-k]=='W') cnt -=1;
        if(s[i]=='W') cnt +=1;
        mini = min(mini,cnt);
    }
    cout<< mini<< endl;
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
        int n , k;
        cin>> n >>k;
        string s ;
        cin >>s;
        solve(s,n,k);
    }

}