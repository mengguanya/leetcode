/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator() (pair<vector<int>::iterator, vector<int>::iterator> iter1, pair<vector<int>::iterator, vector<int>::iterator> iter2) {
            return *iter1.first > *iter2.first;
        }
    };

    vector<int> smallestRange(vector<vector<int> >& nums) {
        priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp> scan;
        int Max = -0X3F3F3F3F;
        int Min = 0X3F3F3F3F;
        vector<int> res;
        int min_range = 0x3f3f3f3f;
        int max_t, min_t;
        int len = nums.size();
        vector<pair<vector<int>::iterator, vector<int>::iterator>> iter;
        
        for (int i = 0; i < nums.size(); i++) {
            pair<vector<int>::iterator, vector<int>::iterator> t(nums[i].begin(), nums[i].end());
            iter.push_back(t);
            scan.push(iter[i]);
            Max = max(Max, *iter[i].first);
        }
        while (1)
        {
            pair<vector<int>::iterator, vector<int>::iterator> i = scan.top();
            Min = *i.first;
            scan.pop();
            if (min_range > Max - Min) {
                min_range = Max - Min;
                max_t = Max;
                min_t = Min;
            }
            
            if (++i.first == i.second) {
                break;
            }
            else {
                scan.push(i);
                Max = max(Max, *i.first);
            }
        }
        res.push_back(min_t);
        res.push_back(max_t);
        return res;
    }
};

// @lc code=end
