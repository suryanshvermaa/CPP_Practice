#include<bits/stdc++.h>
using namespace std;
string rangeOfK(vector<int> &arr){
    float minVal=INT_MAX;
    float maxVal=INT_MIN;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            minVal=min(minVal,((float)arr[i]+arr[i+1])/2);
        }else{
            maxVal=max(maxVal,((float)arr[i]+arr[i+1])/2);
        }
    }
    if(minVal>maxVal)return "Not Possible";
    string ans="kmin:->"+to_string(minVal)+",kmax:->"+to_string(maxVal);
    return ans;
}
int main(){
    vector<int> arr={5,3,8};
    cout<<rangeOfK(arr)<<endl;
    return 0;
}