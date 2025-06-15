#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int> &arr,int target){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target) return arr[mid];
        else if(target>arr[mid]) lo=mid+1;
        else hi=mid-1;
    }
    return arr[hi];
}
int main(){
    vector<int> arr={1,4,5,6,7,8,9,10,34};
    cout<<binary_search(arr.begin(),arr.end(),8)<<endl;
    cout<<*lower_bound(arr.begin(),arr.end(),11)<<endl;
    cout<<upper_bound(arr,11)<<endl;
    return 0;
}