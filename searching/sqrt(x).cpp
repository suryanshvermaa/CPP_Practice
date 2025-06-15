#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
    int lo=0;
    int hi=n;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid==n/mid) return mid;
        else if(mid>n/mid) hi=mid-1;
        else lo=mid+1;
    }
    return hi;
}
int main(){
    cout<<"Enter Number: ";
    int n;
    cin>>n;
    cout<<sqrt(n)<<endl;
    return 0;
}