#include <iostream>
using namespace std;
#include <bits/stdc++.h>


/*


You are given a permutation p of integers from 0 to n−1 (each of them occurs exactly once). Initially, the permutation is not sorted (that is, pi>pi+1 for at least one 1≤i≤n−1).

The permutation is called X-sortable for some non-negative integer X if it is possible to sort the permutation by performing the operation below some finite number of times:
Choose two indices i and j (1≤i<j≤n) such that pi&pj=X.
Swap pi and pj.
Here & denotes the bitwise AND operation.
Find the maximum value of X such that p is X-sortable. It can be shown that there always exists some value of X such that p is X-sortable.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104)  — the number of test cases. Description of test cases follows.
The first line of each test case contains a single integer n (2≤n≤2⋅105)  — the length of the permutation.
The second line of each test case contains n integers p1,p2,...,pn (0≤pi≤n−1, all pi are distinct)  — the elements of p. It is guaranteed that p is not sorted.
It is guaranteed that the sum of n over all cases does not exceed 2⋅105.

Output
For each test case output a single integer — the maximum value of X such that p is X-sortable.



*/

//SOLUTION
/*

We always have to make at least one swap for the elements which are not at their correct positions. Hence an upper bound of answer would be the bitwise AND of those elements. Let the value be X. It turns out that the given permutation is X-sortable.

Proof:

First, notice that X would always be present in p. Let posx be the position of X in p initially. 
Let's say at some point we want to swap two values pi and pj, then pi and pj would always be a supermask of X i.e. pi & X=X and pj & X=X. 
We can make the following moves to swap pi and pj without disturbing any other element.

Swap values at indices i and posx.
Swap values at indices i and j.
Swap values at indices j and posx.
It can be seen that in every swap the bitwise AND of two values which we are swapping is always X. Hence we can swap any two values which were not at their correct positions, therefore we can sort the permutation p.

Overall Complexity: O(n).



*/


void solve(vector<int> &v){
    int maxi = INT_MAX;
    for(int i=0;i<v.size();i++){
     if(v[i]!=i){
        maxi = maxi& v[i];
     }   
    }
    cout<< maxi<<endl;

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
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            
        }
        solve(v);
    }



}