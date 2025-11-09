class Solution {
public:
  int  f(int no,int N,int M){
    int ans=1;
    for(int i=0;i<N;i++){
      ans*=ans;
      if(ans>M) return -1;
    }
    return ans;
  }
  int NthRoot(int N, int M) {
       int lo=1;
       int hi=M;
       while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(f(mid,N,M)==M) return mid;
        else if(f(mid,N,M)==-1) hi=mid-1;
        else lo=mid+1;
       }
       return -1;
  }
};
