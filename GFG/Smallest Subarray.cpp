#include <iostream>
using namespace std;
#include <bits/stdc++.h>



int smallestSubWithSum(int arr[], int n, int x)
{
    int ans=INT_MAX;
    int i=0,j=0;

    if(n==1){
        ans = (arr[0]>x) ? 1 : 0;
        return ans;
    }
    int sum=0;
    while( j<n){
        if(sum<=x){
            sum +=arr[j];
            j++;
        }else{
            sum = sum - arr[i];
            i++;
            ans = min(ans, j-i+1);
            
        }
    }
    while(i<n){
        if(sum<=x){
            break;
        }else{
            sum = sum - arr[i];
            i++;
            ans = min(ans,j-i+1);
            
        }
    }
    
    return min(ans,n);

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n>>c;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin >>x;
        arr[i] =x;
    }
    cout<< smallestSubWithSum(arr,n,c) ;
}