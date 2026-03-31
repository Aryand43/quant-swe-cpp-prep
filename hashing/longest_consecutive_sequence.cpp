#include <unordered_set> 
#include <vector> 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int best = 0; 
        for(int x : s) {
            if (!s.count(x - 1)) {
                int cur = x; 
                int len = 1; 
                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best; 
    }
};
