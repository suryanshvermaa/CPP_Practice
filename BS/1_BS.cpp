#include<bits/stdc++.h>
using namespace std;
int binary_searchRec(vector<int> &arr,int x,int lo,int hi){
    if(lo>hi) return -1;
    int mid=lo+(hi-lo)/2;
    if(arr[mid]==x) return mid;
    else if(x>arr[mid]) return binary_searchRec(arr,x,mid+1,hi);
    else return binary_searchRec(arr,x,lo,mid-1);
}
int binary_searchIt(vector<int> & arr,int x){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x) return mid;
        else if(x>arr[mid]) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}
int main(){
    vector<int> arr={1,3,4,5,6,78,88};
    cout<<binary_searchRec(arr,6,0,arr.size()-1)<<endl;
    return 0;
}