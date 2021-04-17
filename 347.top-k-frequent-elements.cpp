/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>  map_nums;
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        for(auto index : nums){
            map_nums[index]++;
        }
        for(auto iter = map_nums.begin(); iter != map_nums.end(); iter++ ){
            pq.push(make_pair(iter->second, iter->first));
            if(pq.size() > map_nums.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end

