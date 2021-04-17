/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int k = 0;
        char c;
        int flag = -1;
        if(strs.empty())
            return "";
        for(;;){
            if(strs[0].length() > k)
                c = strs[0][k];
            else 
                break;
            flag = 0;
            for(int i = 1; i < n; i++){
                if((strs[i].length() > k) && (strs[i][k] == c)){
                    continue;
                }
                flag = 1;
                break;
            }
            if(flag == 1)
                break;
            k++;
        }
        if(k == -1)
            return "";
        return strs[0].substr(0,k);
    }
};
// @lc code=end

