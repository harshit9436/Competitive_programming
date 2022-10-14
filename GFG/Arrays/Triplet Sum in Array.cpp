
#include <iostream>
using namespace std;
#include <bits/stdc++.h>


bool find3Numbers(int A[], int n, int X)
{
    for(int i=0;i<n;i++){
        unordered_map<int,int> mp;
        int target = X - A[i];
        for(int j=0;j<n;j++){
            if(j!=i){
                mp[A[j]]++;
            }
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            int target2 = target - (*it).first;
            if(mp.find(target2) !=mp.end() ){
                if( mp.find(target2)!=it || mp[target2]>1){
                    return true;
                }

            }
        }
    }
    return false;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

