class Solution {
public:
    int search(vector<int>& nums, int x) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==x) return mid;
            else if(nums[mid]==nums[lo]&&nums[mid]==nums[hi]){
                lo++;
                hi--;
            }
            // left portion sorted or not
            else if(nums[lo]<=nums[mid]){
                if(x>=nums[lo]&&x<=nums[mid]) hi=mid-1;
                else lo=mid+1;
            }else{
                if(x>=nums[mid]&&x<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};