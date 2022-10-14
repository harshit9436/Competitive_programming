#include <iostream>
using namespace std;
#include <bits/stdc++.h>


long long maxProduct(vector<int> arr, int n) {
    long long int neg=1,pos=1;
    long long int ans =arr[0];
    if(n==1) return arr[0];

    for(int i=0;i<n;i++){
        long long temp = pos;
        pos = max((long long) arr[i],max(pos*arr[i], neg*arr[i]));
        neg = min((long long) arr[i] , min(temp*arr[i],neg*arr[i]));
        ans = max(ans,max(pos,neg));

        // ans = max(ans,pos);
    }
    return ans;
    // code here
}


    //  int a =1; int b=1;
    //     int ans = nums[0];
    //     int n = nums.size();
    //     if(n==1) return ans;
    //     for(int i=0;i<n;i++){
    //         int temp = a*nums[i];
    //         a = max(a*nums[i],max(b*nums[i], nums[i]));
    //         b = min(temp,min(b*nums[i], nums[i]));
    //         ans = max(a,max(ans,b));
            
    //     }
    //     return ans;
        

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxProduct(arr,n);

}