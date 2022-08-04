#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*
The MEX of a set of integers is defined as the smallest positive integer that does not
belong to the array. For example, the MEX of {1, 3, 4, 3, 4} is 2 and that of {1, 2, 3, 4} is 5.
Given an array arr of n integers and an integer k, run the array through the following
algorithm exactly k times:
    1. Create an array temp of size n
    2. Set temp[i] = MEX(arr[0], arr[1], arr[2] ... arr[i]) for all i from 0 to n - 1
    3. Set arr[i] = temp[i] for all i from 0 to n - 1
Optimize the algorithm and find the final array.

Example
    Suppose n = 4, arr = [4, 1, 2, 3] and k = 2
    After the 1st
    iteration arr = [1, 2, 3, 5].
    After the 2nd
    iteration arr = [2, 3, 4, 4].
    The answer is [ 2, 3, 4, 4 ].

*/

int solve(vector<int> &v, int j, int last){
    vector<int> temp;
    for(int i=0;i<=j;i++){
        temp.push_back(v[i]);
    }
    if(temp[temp.size()-1] != last){
        return last;
    } 
    sort(temp.begin(), temp.end());
    int ans =1;
    for(int i=0;i<=j;i++){
        if(temp[i] == i+1){
            ans++;
        }else{
            return ans;
            break;
        }   
    }


    return ans;
}


vector<int> getMEX(vector<int> &v, int k){

    for(int i=0;i<k;i++){
        vector<int> temp;
        int last=v[0];
        for(int j=0;j<v.size();j++){
            int a = solve(v,j, last);
            last =a;
            temp.push_back(a);  
        }
        for(int c=0;c<v.size();c++){
            v[c] = temp[c];
        }
    }
    return v;

}

int main(){

    vector<int> v = {4,1,3,2};
    int k=1;

    vector<int> a =  getMEX(v,k);

    for(int i=0;i<v.size();i++){
        cout<< v[i] << " ";
    }

}