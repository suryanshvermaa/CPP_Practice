#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int minEl=INT_MAX;
        int minIdx=-1;
        for(int j=i;j<n;j++){
            if(arr[j]<minEl){
                minEl=arr[j];
                minIdx=j;
            }
            if(minIdx!=-1) swap(arr[minIdx],arr[i]);
        }
    }
}
int main(){
    vector<int> arr={3,5,1,0,33,44,22,1};
    selection_sort(arr);
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}