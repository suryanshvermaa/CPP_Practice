#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> &arr,int target){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
int main(){
    vector<int> arr={1,4,5,6,7,8,9,10,34};
    cout<<"Index of number is: "<<binary_search(arr,44)<<endl;
    return 0;
}