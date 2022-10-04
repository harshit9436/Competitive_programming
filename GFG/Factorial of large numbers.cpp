#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void multiply(vector<int> &v, int k){
    int c =0;
    for(int i=v.size()-1;i>=0;i--){
        int temp = (v[i]*k +c) %10;
        c = (v[i]*k+c)/10;
        v[i] = temp;
    }

    if(c >0){
        v.insert(v.begin(), c);
    }


}

vector<int> factorial(int n){
    vector<int> ans ;
    ans = {1};
    int c=0;
    for(int i=0;i<n;i++){
        multiply(ans , i+1);
    }
    return ans;

}


int main(){

    vector<int> ans =factorial(7);
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<< " ";
    }
}