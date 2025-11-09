class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int hi=nums.size()-1;
        int lo=0;
        int ans=INT_MAX;
        int minIdx=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[mid]){
                if(ans>nums[lo]){
                    ans=nums[lo];
                    minIdx=lo;
                }
                lo=mid+1;
            }else{
                if(ans>nums[0]){
                    ans=nums[mid];
                    minIdx=mid;
                }
                hi=mid-1;
            }
        }
        return minIdx;

    }
};