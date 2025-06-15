#include<bits/stdc++.h>
using namespace std;
void push_zeroes_at_end(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]==0) swap(arr[j],arr[j+1]);
            flag=false;
        }
        if(flag) return;
    }
}
int main(){
    vector<int> arr={5,0,1,2,0,0,4,0,3};
    push_zeroes_at_end(arr);
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}