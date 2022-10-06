#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int countOccurence(int arr[], int n, int k) {
    vector<pair<int,int>> v(k-1,{0,0});

    for(int i=0;i<n;i++){
        int j;

        for(j=0;j<k-1;j++){
            if(v[j].first==arr[i]){
                v[j].second+=1;
                break;
            }
        }
        if(j==k-1){
            int l;
            for(l=0;l<k-1;l++){
                if(v[l].second==0){
                    v[l].first = arr[i];
                    v[l].second = 1;
                    break;
                }
            }
            if(l==k-1){
                for(l=0;l<k-1;l++){
                    v[l].second--;
                }
            }
        }
    }

    int x =n/k;
    int ans =0;
    for(auto it=v.begin();it!=v.end();it++){
        int cnt= 0;
        for(int i=0;i<n;i++){
            if((*it).first ==arr[i]&&(*it).second>0){
                cnt++;
            }
        }
        
        if(cnt>x){
            ans++;
        }
    }
    return ans;
    
    }

int main(){
    #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin >> k;
        cout<<countOccurence(arr,n,k)<<endl;
    

}