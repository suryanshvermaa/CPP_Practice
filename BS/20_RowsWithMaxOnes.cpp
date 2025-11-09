class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int maxOnes=0;
    int idx=-1;
    for(int i=0;i<mat.size();i++){
      int lo=0;
      int hi=mat[i].size()-1;
      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mat[i][mid]==1) hi=mid-1;
        else lo=mid+1;
      }
      if(maxOnes<(mat[i].size()-lo)){
        maxOnes=mat[i].size()-lo;
        idx=i;
      }
    }
    return idx;
  }
};