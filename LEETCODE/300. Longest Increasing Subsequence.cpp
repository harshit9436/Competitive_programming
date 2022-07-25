//link https://leetcode.com/problems/longest-increasing-subsequence/submissions/

//Complex solution in O(NlogN)
class Solution {
public:
    
    int LSI(vector<int> arr, int size){
        
        vector<int> map;
        map.push_back(arr[0]);
        int ans=1;
        for(int i=1;i<size;i++){
            if(arr[i]>map.back()){
                map.push_back(arr[i]);
                ans++;
            }else{
            auto it = lower_bound(map.begin(),map.end(),arr[i])- map.begin();
            map[it] = arr[i];
            }
        
        }

        return ans;
        
        
}
    
    
    int lengthOfLIS(vector<int>& arr) {
        return LSI(arr, arr.size());
    }
};


// More feasible solution O(N^2)
class Solution {
public:
    
    int LSI(vector<int> arr, int size){
    int s[size];
        cout<< size<< endl;
    for(int i = 0; i < size; i++){
        s[i] = 0;
    }

    int ans=0;


    for(int i=0;i<size;i++){
        int max=0;
        for(int j=i; j>=0;j--){
            if(arr[j] < arr[i]){
                max = max > s[j] ? max : s[j];
            }
        }
        s[i]= max+1;
        ans = ans > s[i] ? ans : s[i];
    }

        cout << ans;
    return ans;
        
}
    
    
    int lengthOfLIS(vector<int>& arr) {
        return LSI(arr, arr.size());
    }
};