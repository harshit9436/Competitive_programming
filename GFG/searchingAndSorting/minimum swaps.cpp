#include <iostream>
using namespace std;
#include <bits/stdc++.h>



int minSwaps(vector<int>&nums)
{
    // Code here
    vector<pair<int,int>> mp;
    for(int i=0;i<nums.size();i++){
        mp.push_back({nums[i],i});
    }
    
    // sort(nums.begin(),nums.end());
    /*vector<pair<int,int>> mp;
    for(int i=0;i<nums.size();i++){
        mp.push_back({old[i].first,old[i].second});
    }
    */
    sort(mp.begin(),mp.end());
    // for(int i=0;i<nums.size();i++){
    //     cout<< mp[i].first << " "<<mp[i].second << endl;    
    //     }
    
    
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(mp[i].second==i){
            // cout<< i<< endl;
            continue;
            
        }else{
            ans++;
            // cout<< i <<"--" <<endl;
            swap(mp[i],mp[mp[i].second]);
            //pair<int,int> temp = mp[i];
            //mp[i] = mp[mp[i].second];
            //mp[mp[i].second]=temp;
            i--;
        } 
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
    
    int n;
    vector<int> v;
    cin >>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
   cout<<  minSwaps(v);
}
