#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        vector<int> freq (128, 0);
        for (char c : t) freq[c]++;
        int need = t.size();
        int bestLen = INT_MAX, bestL = 0;
        for(int l = 0, r = 0; r < (int)s.size(); r++) {
            if (freq[s[r]]>0) need--;
            freq[s[r]]--;
            while(need==0){
                if(r - l + 1 < bestLen){
                    bestLen = r - l + 1;
                    bestL = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) need++;
                l++;
            }
        }
        return bestLen == INT_MAX ? "":  s.substr(bestL, bestLen);
    }
};
