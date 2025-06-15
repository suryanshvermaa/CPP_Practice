#include<bits/stdc++.h>
using namespace std;
int smallest_missing_element(vector<int> &arr){
    int n=arr.size()-1;
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]!=mid){
            if(mid>0&&arr[mid-1]==mid-1) return mid;
            else hi=mid-1;
        }
        else if(arr[mid]==mid) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
int main(){
    vector<int> arr={0,1,2,3,4,6,7,8,9,11};
    cout<<smallest_missing_element(arr)<<endl;
    return 0;
}