class Solution {
public:
    int f(int A,vector<int>&arr,int maxUnit){
        int lastUnit=0;
        for(auto el:arr){
            if(el+lastUnit<=maxUnit) lastUnit+=el;
            else{
                A--;
                lastUnit=el;
            }
        }
        if(lastUnit) A--;
        return A>=0;
    }
    int sum(vector<int>&arr){
        int s=0;
        for(auto el:arr) s+=el;
        return s;
    }
    int paint(int A, int B, vector<int>& C) {
        int lo=*max_element(C.begin(),C.end());
        int hi=sum(C);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(A,C,mid)) hi=mid-1;
            else lo=mid+1;
        }
        int ans=(1LL*B*lo)%10000003;
        return ans;
    }
};