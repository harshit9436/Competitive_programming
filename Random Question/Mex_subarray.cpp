#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/*
Given an array arr of n integers that contains all the integers from 1 to n and an integer
k, find the kth smallest MEX of a subarray of the array. That is, in a list containing MEX
of all the subarrays, find the kth smallest integer.
The MEX of an array is the smallest positive integer not present in the array. 

For example, the MEX of [1, 2, 3] is 4 and that of [1, 3, 4, 5] is 2.
A subarray is any contiguous segment of the array.

Example
    Suppose n = 4, arr = [3, 2, 1, 4], and k = 5,
    The MEX of each subarray is:
    Subarrays [3], [2], [1], and [4] have MEX 1, 1, 2, and 1 respectively.
    Subarrays [3, 2], [2, 1] and [1, 4] have MEX 1, 3, and 2 respectively.
    Subarrays [3, 2, 1] and [2, 1, 4] have MEX 4 and 3 respectively.
    Subarray [3, 2, 1, 4] has MEX 5.
All MEX values in ascending order are [1, 1, 1, 1, 2, 2, 3, 3, 4, 5]. The 5th smallest value is
2. Hence, the answer is 2.

*/

int solve(vector<int> &v,int i, int j){
    vector<int> temp;
    for(int k=i;k<=j;k++){
        temp.push_back(v[k]);
    }
    sort(temp.begin(), temp.end());
    int ans =1;
    for(int k=0;k<=temp.size();k++){
        if(temp[k] == k+1){
            ans++;
        }else{
            return ans;
            break;
        }   
    }


    return ans;
}


int getMEX(vector<int> &v, int k){
    vector<int> temp;
        for(int i=0;i<v.size();i++){
            for(int j=i;j<v.size();j++){
                int a = solve(v,i,j);
                temp.push_back(a);

            }
        }

        sort(temp.begin(), temp.end());
    //        for(int i=0;i<temp.size();i++){
    //         cout<< temp[i]<<" ";
    // }
        return temp[k-1];

}


int main(){

    vector<int> v = {3, 2, 1, 4};
    int k=5;

    cout<< getMEX(v,k);


}