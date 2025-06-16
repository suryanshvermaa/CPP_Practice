/**
 * @details Taro and Jiro will play the following game against each other.
 * 
 * Initially they are given a sequence=(a1,a2,a3,...,an). Untill a becomes empty. the 2 players perform
 * the following opertion alternatily, stating from taro. 
 * 
 * Remove the element at the beginning or the end of a. The player earns x points, where x is the 
 * removed element.
 * 
 * Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximise
 * X-Y, while Jiro tries to minimize X-Y. 
 * Assuming that 2 player play optimally, find resulting value of X-Y.
 */
#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005];
int ans(vector<int> &arr,int i,int j){
    if(i==j) return arr[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(arr[i]-ans(arr,i+1,j),arr[j]-ans(arr,i,j-1));
}
int main(){
    vector<int> arr={4,2,9,7,1,5};
    memset(dp,-1,sizeof dp);
    cout<<ans(arr,0,arr.size()-1)<<endl;
    return 0;
}