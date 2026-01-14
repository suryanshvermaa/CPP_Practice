#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void buildST(vector<int>&arr,vector<int>&seg,int lo,int hi,int idx){
    if(lo==hi){
      seg[idx]=arr[lo];
      return;
    }
    int mid=(lo+hi)/2;
    buildST(arr,seg,lo,mid,2*idx+1);
    buildST(arr,seg,mid+1,hi,2*idx+2);
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
}
int minInRange(vector<int>&arr,vector<int>&seg,int lo,int hi,int idx,int l,int r){
    // no overlap
    if(hi<l||lo>r) return INT_MAX;
    // complete overlap
    else if(l<=lo&&hi<=r) return seg[idx];
    // partial overlap
    int mid=(lo+hi)/2;
    int leftMin=minInRange(arr,seg,lo,mid,2*idx+1,l,r);
    int rightMin=minInRange(arr,seg,mid+1,hi,2*idx+2,l,r);
    return min(leftMin,rightMin);
}
int main(){
    vector<int> arr={29,23,49,23,45,56,24};
    vector<int> seg(4*arr.size());
    buildST(arr,seg,0,arr.size()-1,0);
    int q;
    cout<<"number of queries:";
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<minInRange(arr,seg,0,arr.size()-1,0,l,r)<<endl;
    }
    return 0;
}