#include <iostream>
using namespace std;
#include <bits/stdc++.h>



/*



Mike and Joe are playing a game with some stones. Specifically, they have n piles of stones of sizes a1,a2,…,an. These piles are arranged in a circle.
The game goes as follows. Players take turns removing some positive number of stones from a pile in clockwise order starting from pile 1. Formally, if a player removed stones from pile i on a turn, the other player removes stones from pile ((imodn)+1) on the next turn.
If a player cannot remove any stones on their turn (because the pile is empty), they lose. Mike goes first.
If Mike and Joe play optimally, who will win?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤50)  — the number of piles.
The second line contains n integers a1,a2,…,an (1≤ai≤109)  — the size of the piles.

Output
For each test case print the winner of the game, either "Mike" or "Joe" on its own line (without quotes).



*/






void solve(int n, vector<int>arr){
	if(n%2==1){
		cout<< "Mike"<< endl;
		return;
	} 

	int i=0;
	for(int j=0;j<n;j++){
		if(arr[j]<arr[i]){
			i = j;
		}
	}
	if(i%2==1){
		cout<< "Mike" <<endl;
	}else{
		cout << "Joe" <<endl;
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
        int n;
        cin>> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        solve(n,arr);
    }

}



