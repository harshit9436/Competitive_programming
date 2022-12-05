#include <iostream>
using namespace std;
#include <bits/stdc++.h>



int solve(int n){
    int ans=0;
    while(true){
        ans += n/5;
        if(n/5==0){
            break;
        }
        n = n/5;
    }
    return ans;
}

int findNum(int n)
{
//complete the function here
    int l=0; int r = 5*n;
    while(l<=r){
        int mid = (l+r)/2;
        int x = solve(mid);
        if(x==n){
            return mid - mid%5;
        }else{
            if(x < n){
                l=mid+1;
            }else{
                r = mid-1;
            }
        }
    }
    
    return l;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >>n;
    cout<<findNum(n);
}