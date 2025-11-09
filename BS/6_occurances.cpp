class Solution {
public:
    int f1(const vector<int>&nums,int x){
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
    int f2(const vector<int>&nums,int x){
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
    int countOccurrences(const vector<int>& arr, int target) {
        int fiestoc=f1(arr,target);
        if(fiestoc==-1) return 0;
        else return f2(arr,target)-fiestoc+1;
    }
};