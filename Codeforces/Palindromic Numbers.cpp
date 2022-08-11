#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*

During a daily walk Alina noticed a long number written on the ground. Now Alina wants to find some positive number of same length without leading zeroes, such that the sum of these two numbers is a palindrome.
Recall that a number is called a palindrome, if it reads the same right to left and left to right. For example, numbers 121,66,98989 are palindromes, and 103,239,1241 are not palindromes.
Alina understands that a valid number always exist. Help her find one!

Input
The first line of input data contains an integer t (1≤t≤100) — the number of test cases. Next, descriptions of t test cases follow.
The first line of each test case contains a single integer n (2≤n≤100000) — the length of the number that is written on the ground.
The second line of contains the positive n-digit integer without leading zeroes — the number itself.
It is guaranteed that the sum of the values n over all test cases does not exceed 100000.

Output
For each of t test cases print an answer — a positive n-digit integer without leading zeros, such that the sum of the input integer and this number is a palindrome.
We can show that at least one number satisfying the constraints exists. If there are multiple solutions, you can output any of them


*/





//either make it 9999..9 or 1111....1 depending upon first digit of n
void solve(string n , int l){

    if(n[0] == '9'){

        int arr[l];
        int r=0;
        for(int i=l-1;i>=0;i--){
            int x = n.at(i) -'0';
            x+=r;
            if(x>1 ){
                arr[i] = 11 -x;
                r=1;

            }else{
                arr[i] = 1-x;
                r=0;
            }
        }
        for(int i=0;i<l;i++){
            cout<< arr[i];
        }
        cout<< endl;

    }else{
        int arr[l];
        for(int i=0;i<l;i++){
            arr[i] = 9- n.at(i) +'0';
            cout<< arr[i];
        }
        cout<< endl;
    }

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
        int l; string n;
        cin>> l>>n;
        solve(n,l);
    }

}