class Solution {
public:
    bool canPlace(vector<int> &arr,int k,int no){
        int lastCoordinate=arr[0];
        k--;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastCoordinate>=k){
                k--;
                lastCoordinate=arr[i];
            }
        }
        return k<=0;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int lo=1;
        int hi=arr[n-1]-arr[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canPlace(arr,k,mid)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};