/**
 * @details Harry Potter has n mixures in front of him, arranged in row. Each mixure has one of 100
 * different colors (colors have numbers from 0 to 99). 
 * 
 * He wants to mix all these mixures together. At each step, he is going to take two mixures that stand
 * next to each other and mix them together. At each step, he is going to take 2 mixures in their place.
 * 
 * When mixing 2 mixures of colors a and b, resulting mixure will have the color (a+b)mod 100.
 * 
 * Also, there will be smoke in the process. The amount of smoke generated when mixing 2 mixures of colors
 * a and b is a*b.
 * 
 * Find out what is the minimum amount of smoke that harry can get when mixing all the mixures together.
 */

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int genSmokeByResMix(vector<int> &colors,int i,int j){
    int ans=0;
    for(int k=i;k<=j;k++){
        ans=(ans%100+colors[k]%100)%100;
    }
    return ans;
}
int minSmoke(vector<int> &colors,int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int smoke=INT_MAX;
    for(int k=i;k<j;k++){
        smoke=min(smoke,minSmoke(colors,i,k)+minSmoke(colors,k+1,j)+genSmokeByResMix(colors,i,k)*genSmokeByResMix(colors,k+1,j));
    }
    return dp[i][j]=smoke;
}
int main(){
    vector<int> colors={40,60,20};
    dp.resize(105,vector<int> (105,-1));
    cout<<minSmoke(colors,0,colors.size()-1)<<endl;
    return 0;
}