

/*
You are given three integers n, l, and r. You need to construct an array a1,a2,…,an (l≤ai≤r) such that gcd(i,ai) are all distinct or report there's no solution.
Here gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

INPUT
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10^4) — the number of test cases. The description of the test cases follows.
The first line contains three integers n, l, r (1≤n≤10^5, 1≤l≤r≤10^9).
It is guaranteed that the sum of n over all test cases does not exceed 10^5.


OUTPUT
For each test case, if there is no solution, print "NO" (without quotes). You can print letters in any case (upper or lower).
Otherwise, print "YES" (without quotes). In the next line, print n integers a1,a2,…,an — the array you construct.
If there are multiple solutions, you may output any.
*/


#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(int n, int l , int r){
    vector<int> arr(n,-1);


    // this condition is wrong bcoz of repeating aloowed , number divisible by 4 can be used for i=1,2,4. therefore with just 2 numbers we can form array of 4.
    // if((r-l +1)<n){
    //     cout << "NO"<< endl;
    //     return;
    // }
    // int index =0;
    bool flag = true;
    for(int i=1;i<=n;i++){
        arr[i-1] =(((l-1)/i) +1 )*i;
        flag = flag && (arr[i-1] <=r);

    }

    if(flag){
        cout <<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout << arr[i] <<" ";
        }cout<< endl;
    }else{
        cout<< "NO" << endl;
    }


    

}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,l, n , r;
    cin >> t;

    for(int i=0;i<t;i++){
            cin >> n>>l>>r;
            solve(n,l,r);
    }

}