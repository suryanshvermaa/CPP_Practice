class Solution {
public:
    typedef pair<long double,int> pp; // (dist,idx)
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int> maxdist(n-1,0);
        vector<long double> nums(n-1,0);
        priority_queue<pp> pq;
        for(int i=0;i<n-1;i++){
            long double currDist = arr[i + 1] - arr[i];
            pq.push({currDist,i});
            nums[i]=currDist;
        }
       while(k--){
        auto [dist,i]=pq.top();
        pq.pop();
        maxdist[i]++;
        dist = (long double)nums[i] / (maxdist[i] + 1);
        pq.push({dist,i});
       }
       return pq.top().first;
    }
};