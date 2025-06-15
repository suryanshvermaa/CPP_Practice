#include<bits/stdc++.h>
using namespace std;
void optimised_bubble_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            flag=false;
        }
        if(flag) break;
    }
}
int main(){
    vector<int> arr={3,5,1,0,33,44,22,1};
    optimised_bubble_sort(arr);
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}