class Solution {
public:
    int sum(vector<int>&nums){
        int s=0;
        for(auto el:nums){
            s+=el;
        }
        return s;
    }
    bool f(vector<int>&arr,int k,int maxSum){
        int lastSum=0;
        for(auto el:arr){
            if(el+lastSum<=maxSum){
                lastSum+=el;
            }else{
                k--;
                lastSum=el;
            }
        }
        if(lastSum) k--;
        return k>=0;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo=*max_element(nums.begin(),nums.end());
        int hi=sum(nums);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(nums,k,mid)) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};