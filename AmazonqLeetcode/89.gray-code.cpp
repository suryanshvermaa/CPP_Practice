/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int ansCnt=pow(2,n)-1;
        for(int i=0;i<=ansCnt;i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};
// @lc code=end

