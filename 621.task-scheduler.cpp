/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nums[26] = {0};
        priority_queue<int> pq;    
        int res = 0;
        for (auto t : tasks)
        {
            nums[t - 'A']++;
        }
        for(int i  = 0; i < 26; i++){
            if(nums[i] != 0){
                pq.push(nums[i]);
            }
        }
        while (1)
        {
            int cnt = 0;
            cnt = pq.size();
            vector<int> t;
            for(int i = 0; (i < pq.size()) && (i < n); i++){
                int x = pq.pop();
                if(--x > 0)
                    t.push(x);
            }
            for(int i = 0;i < t.size(); i++){
                pq.push(t[i]);
            }
            if (cnt >= n){
                res += cnt;
            }        
            else if(cnt > 0){
                res+= n;
            }
            else{
                break;
            }
        }
        return res;
    }
};
// @lc code=end

