/**
 * @details Any programmer worth his salt would be familiar with the famous Longest common sequence problem. Mancunian
 * was asked to solve the same by an incompetent programmer. As expected, he solved in flash. To complicate
 * matters, a twist was introduces in the problem.
 * 
 * In addition to the sequences , an additional parameter k was introduced. A k-ordered LCS is defined to be the 
 * LCS of 2 sequences if you are allowed to change at most k elements in the first seqence to any value you wish
 * to. Can you help mancunian solve this version of the classical problem.
 */
#include<bits/stdc++.h>
using namespace std;
/**
 * @param n -> first sequence
 * @param m -> second sequence
 * @param k -> at most elements that can be changes
 */
int dp[2000][2000][6];
int korderedLCS(vector<int>& n,vector<int>& m, int k,int i,int j){
    if(i==n.size()||j==m.size()) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(n[i]==m[j]){
        return dp[i][j][k]=1+korderedLCS(n,m,k,i+1,j+1);
    }else{
        int maxAns=INT_MIN;
        if(k>0) maxAns=max(maxAns,1+korderedLCS(n,m,k-1,i+1,j+1));
        maxAns=max(maxAns,korderedLCS(n,m,k,i+1,j));
        maxAns=max(maxAns,korderedLCS(n,m,k,i,j+1));
        return dp[i][j][k]=maxAns;
    }
}
int main(){
    vector<int> n={1,2,3,4,5};
    vector<int> m={5,3,1,4,2};
    int k=1;
    memset(dp,-1,sizeof dp);
    cout<<korderedLCS(n,m,k,0,0)<<endl;
    return 0;
}