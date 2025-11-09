class Solution {
public:
    bool f(vector<int>&arr,int m,int maxPages){
        int prevPages=0;
        for(auto el:arr){
            if(prevPages+el<=maxPages) prevPages+=el;
            else {
                m--;
                prevPages=el;
            }
        }
        if(prevPages){
            m--;
        }
        if(m>0) return false;
        return true;
    }
    int sum(vector<int>&arr){
        int s=0;
        for(auto el:arr){
            s+=el;
        }
        return s;
    }
    int findPages(vector<int> &nums, int m)  {
        int lo=*max_element(nums.begin(),nums.end());
        int hi=sum(nums);
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(nums,m,mid)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};