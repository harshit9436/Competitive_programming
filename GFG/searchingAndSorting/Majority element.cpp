#include <iostream>
using namespace std;
#include <bits/stdc++.h>


 int majorityElement(int arr[], int size){

    // your code here
    int freq =1;
    int x =arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]==x){
            freq++;
        }else{
            if(freq ==0){
                x = arr[i];
                freq =1;
            }else{
                freq--;     
            }
                
            
        }
    }

    int cnt=0;
    for(int i=0;i<size;i++){
        if(arr[i]==x){
            cnt++;
        }
    }
    // cout<< x << " "<< cnt;
    if(cnt>size/2){
        return x;
    }else{
        return -1;
    }

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int n;
    // cin >>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // majorityElement(arr,n);
 
}