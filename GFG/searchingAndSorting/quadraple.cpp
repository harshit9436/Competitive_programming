#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> result;
        int n = arr.size();
        sort(arr.begin() , arr. end());
        for(int i = 0; i < n - 3; ++i){
            if(i == 0 || (i > 0 && arr[i] != arr[i-1])){
                for(int j = i + 1; j < n - 2; ++j){
                    if(j == i + 1 || j > i + 1 && arr[j] != arr[j - 1]){
                        int low = j + 1 , high = n - 1;
                        long long int sum = 0ll + k - (arr[i] + arr[j]);
                        while(low < high){
                            if(arr[low] + arr[high] == sum){
                                vector<int> temp;
                                temp.push_back(arr[i]);
                                temp.push_back(arr[j]);
                                temp.push_back(arr[low]);
                                temp.push_back(arr[high]);
                                result.push_back(temp);
                                while(low < high && arr[low] == arr[low + 1]) low++;
                                while(low < high && arr[high] == arr[high - 1]) high--;
                                low++; high--;
                            }
                            else if(arr[low] + arr[high] < sum) low++;
                            else high--;
                        }
                    }
                }
            }
        }
        return result;
    }

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,target;
    cin >>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
     fourSum(v,target);
 
}