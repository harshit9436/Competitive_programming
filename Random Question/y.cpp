
#include <iostream>
using namespace std;
#include <bits/stdc++.h>



int subsetSumToK(int arr[], int n,
            int output[][50], int k){
     
    // Base Case
    if (n == 0) {
        if (k == 0) {
            output[0][0] = 0;
            return 1;
        }
        else {
            return 0;
        }
    }
     
    
    int output1[1000][50];
     

    int output2[1000][50];
     

    int size1 = subsetSumToK(arr + 1,
        n - 1, output1, k - arr[0]);

    int size2 = subsetSumToK(arr + 1, n - 1,
                                output2, k);
 
    int i, j;

    for (i = 0; i < size1; i++) {

        output[i][0] = output1[i][0] + 1;

        output[i][1] = arr[0];
    }

    for (i = 0; i < size1; i++) {
        for (j = 1; j <= output1[i][0]; j++) {
            output[i][j + 1] = output1[i][j];
        }
    }

    for (i = 0; i < size2; i++) {
        for (j = 0; j <= output2[i][0]; j++) {
            output[i + size1][j] = output2[i][j];
        }
    }
     
    return size1 + size2;
}

void countSubsequences(int arr[], int n, int output[][50], int k, string str)
{  
    int size = subsetSumToK(arr, n, output, k);
     int mini = INT_MAX;
     int a =0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j <= output[i][0]; j++) {
            // cout << output[i][j] << " ";
            if(output[i][j]<mini){
                mini = output[i][j];
                a = j;
            }
        } 
    }   
    string x = "";
    int g =0;
    for (int j = 1; j <= output[k][0];) {
        if((str[g] -'0')== output[k][j]){
            x += "+";
            j++;
        }else{
            x+="-";
        }
    } 
    cout<<x;
     
}
 
// Driver Code
int main()
{

     #ifndef ONLINE_JUDGE
        freopen("zinput.txt" , "r" , stdin);
        freopen("zoutput.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // int length = 9, output[1000][50], k = 5;
    // string str = "35132";
    string str;
    cin >>str;
    int length = str.length();
    int output[1000][50];
    int k = 0;
    int arr[str.size()];
    for(int i = 0; i < str.size(); i++){
        arr[i] = str[i]-'0';
    }
 
    countSubsequences(arr, length, output, k, str);
 
    return 0;
}