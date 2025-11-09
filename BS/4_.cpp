class Solution {
public:
    int floor(vector<int>&nums,int x){
        int lo=0;
        int hi=nums.size()-1;
        int ans=nums.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=x){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
    int ceil(vector<int>&nums,int x){
        int lo=0;
        int hi=nums.size()-1;
        int ans=nums.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=x){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        return {nums[floor(nums,x)],nums[ceil(nums,x)]};
    }
};