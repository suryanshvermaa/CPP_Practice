class Solution {
public:
    int f1(vector<int>&nums,int x){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==x){
                ans=mid;
                hi=mid-1;
            }
            else if(x>nums[mid]) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    int f2(vector<int>&nums,int x){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==x){
                ans=mid;
                lo=mid+1;
            }
            else if(x>nums[mid]) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f1(nums,target),f2(nums,target)};
    }
};