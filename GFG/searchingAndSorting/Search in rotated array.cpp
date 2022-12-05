#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int search(vector<int>& nums, int target) {
    int l =0, r= nums.size()-1;
    while(l<=r){
        cout<< l << " " << r<< endl;
        int mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[l]<= nums[mid]){
            if(target <= nums[mid]&& target >= nums[l]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }else{
            if(target <= nums[r] &&target >= nums[mid] ){
                l= mid+1;
            }else{
                r= mid-1;
            }
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
}
