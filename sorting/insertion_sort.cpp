#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=0&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
int main(){
    vector<int> arr={3,5,1,0,33,44,22,1};
    insertion_sort(arr);
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}