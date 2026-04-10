#include <unordered_map>
using namespace std; 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, n = s.size(), bestLen = 0;
        std::unordered_map<char, int> check;
        for(int right = 0; right < n; ++right) {
            char c = s[right];
            if (check.count(c)) {
                int prev = check[c];
                if (prev >= left) {
                    left = prev + 1; 
                }
            }
            check[c] = right;
            int len = right - left + 1; 
            bestLen = max(bestLen, len);
        }
        return bestLen;
    }
};
