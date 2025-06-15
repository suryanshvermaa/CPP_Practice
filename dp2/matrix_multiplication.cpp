#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int minMultiplications(vector<int> &arr, int i, int j){
    if(i==j||i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j]; 
    int minMul=INT_MAX;
    for(int idx=i+1;idx<j;idx++){
        minMul=min(minMul,minMultiplications(arr,i,idx)+minMultiplications(arr,idx,j)+arr[i]*arr[idx]*arr[j]);
    }
    return dp[i][j]=minMul;
}
int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    dp.resize(arr.size()+1,vector<int> (arr.size()+1,-1));
    cout << minMultiplications(arr, 0, arr.size()-1)<<endl;
    return 0;
}