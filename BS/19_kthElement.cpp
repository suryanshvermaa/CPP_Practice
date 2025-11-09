class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return kthElement(b,a);
        int lo=0;
        int hi=n1;
        while(lo<=hi){
            int mid1=lo+(hi-lo)/2;
            int mid2=k-mid1;
            int r1=INT_MAX, r2=INT_MAX, l1=INT_MIN, l2=INT_MIN;
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=a[mid2-1];
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=a[mid2];
            if(l1<=r2&&l2<=r1) return max(l1,l2);
            else if(l1>r2) hi=mid-1;
            else lo=mid+1
        }
        return 0;
    }
};