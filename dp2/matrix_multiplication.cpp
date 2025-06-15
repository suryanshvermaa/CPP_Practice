#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int minMultiplications(vector<int> &arr, int i, int j){
    if(i==j||i==j-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int minNo=INT_MAX;
    for(int k=i+1;k<j;k++){
        minNo=min(minNo,minMultiplications(arr,i,k)+minMultiplications(arr,k,j)+arr[i]*arr[j]*arr[k]);
    }
    return minNo;
}
int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    dp.resize(arr.size()+1,vector<int> (arr.size()+1,-1));
    cout << minMultiplications(arr, 0, arr.size()-1)<<endl;
    return 0;
}