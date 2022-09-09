#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int minJumps(int arr[], int n){
        // Your code here
        int l=0,r=0;
        if(arr[0]==0) return -1;
        int maxi=-1,cnt=0;
        while(r<n-1){
            for(int i=l;i<r;i++){
                maxi = max(maxi,i+arr[i]);
            }
            l =r+1;
            r = maxi;
            cnt++;
            if(maxi==0){
                return -1;
            }
        }
        return cnt;
        
    }
int main(){

    int arr[11] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << minJumps(arr,11);
}