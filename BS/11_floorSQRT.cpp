class Solution {
public:
    int floorSqrt(int n)  {
      int lo=1;
      int hi=n;
      int ans=1;
      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int sqMid=mid*mid;
        if(sqMid<=n){
            ans=mid;
            lo=mid+1;
        }else hi=mid-1;
      }
      return ans;
    }
};