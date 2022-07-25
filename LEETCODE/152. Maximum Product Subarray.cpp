// link https://leetcode.com/problems/maximum-product-subarray/


//Important used two pointers to be used for negative and positive nums[i]
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int a =1; int b=1;
        int ans = nums[0];
        int n = nums.size();
        if(n==1) return ans;
        for(int i=0;i<n;i++){
            int temp = a*nums[i];
            a = max(a*nums[i],max(b*nums[i], nums[i]));
            b = min(temp,min(b*nums[i], nums[i]));
            ans = max(a,max(ans,b));
            
        }
        return ans;
        
    }
};