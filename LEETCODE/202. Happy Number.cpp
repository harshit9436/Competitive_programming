#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Easy way to store element in map and check if repitition occured.
//using double pointer we can find if numbers are repititing in

long long int square(int n){
    long long int sum =0;
    while(n!=0){
        int a = n%10;
        sum +=a*a;
        n = n/10;
    }
    return sum;
}

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        do{
            slow = square(slow);
            fast = square(square(fast));
            cout << slow <<" "<< fast << endl;
            
        }
        while(slow != fast);
            return slow == 1;
        
    }
int main(){

#ifndef ONLINE_JUDGE
    freopen("zinput.txt" , "r" , stdin);
    freopen("zoutput.txt" , "w" , stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
   cout<< isHappy(n);
}
