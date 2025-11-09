class Solution {
public:
    bool f(vector<int>& piles,int k,int h){
        for(int i=0;i<piles.size();i++){
            int div=piles[i]/k;
            int mod=piles[i]%k;
            h-=div;
            if(mod>0) h--;
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=*max_element(piles.begin(),piles.end());
        int lo=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(piles,mid,h)) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};