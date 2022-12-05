#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// bool com(pair<int,int> a, pair<int,int> b){
//     if(a.second != b.second){
//         return a.second > b.second;
//     }
//     return a.first < b.first;
// }


bool com(int a, int b){

    int cnt =0;
    while(a>0){
        cnt += (1 & a);
        a = a >> 1;
    }
    
    
    int cnt1 =0;
    while(b>0){
        cnt1 += (1 & b);
        b = b >> 1;
    }
    
    return cnt < cnt1;

}


void sortBySetBitCount(int arr[], int n)
{
    // Your code goes here
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] =arr[i];
        int cnt =0;
        int a = v[i];
        while(a>0){
            cnt += (1 & a);
            a = a >> 1;
    }
    cout << cnt<< " " << v[i] <<endl;
    }
    sort(v.begin(),v.end(),com);
    
    for(int i=0;i<n;i++){
        arr[i] =v[i];
        // cout<< arr[i] << " ";
    }
}


int main(){
    // vector<pair<int,int>> v;
    // v.push_back({1,2});
    // v.push_back({1,1});
    // v.push_back({2,2});
    // v.push_back({5,4});
    // v.push_back({0,10});
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,target;
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // sort(v.begin(),v.end(),com);
    sortBySetBitCount(arr,n);




}