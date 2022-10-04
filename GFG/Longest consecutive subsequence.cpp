#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int LCS(int arr[] , int N){
    map<int,bool> mp;
    for(int i=0;i<N;i++){
        mp.insert({arr[i],false});
    }
    int ans =0;
    for(int i=0;i<N;i++){
        int cnt =0;
        if(!mp[arr[i]]){
            int x = arr[i];
            while(mp.find(x)!=mp.end()){
                cnt ++;
                mp[x]=true;
                x--;
            }
            x = arr[i] +1;
            while(mp.find(x)!=mp.end()){
                cnt ++;
                mp[x] = true;
                x++;
            }
        }
        ans = max(ans,cnt);
    }

    return ans;


}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}