/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        char* star = nullptr;
        char* ss = s;
        while (*s)
        {
            if( *s == *p || *p == '?'){
                s++;
                p++;
            }
            else if(*p == '*'){
                ss = s;
                star = p++;
            }
            else if(star){
                s = +ss;
                p = star + 1;
            }
            else{
                return false;
            }
        }
        while (*p == '*')
        {
            p++;
        }
        return !*p;
    }
};
// @lc code=end

