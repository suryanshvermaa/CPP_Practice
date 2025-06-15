#include<bits/stdc++.h>
using namespace std;
int first_occrance_of_x(vector<int> &arr,int x){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            if(mid>0&&arr[mid-1]==x) hi=mid-1;
            else return mid;
        }
        else if(x>arr[mid]) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
int main(){
    vector<int> arr={1,4,3,3,3,3,3,4,4,4,4,9,10,34};
    cout<<first_occrance_of_x(arr,3)<<endl;
    return 0;
}