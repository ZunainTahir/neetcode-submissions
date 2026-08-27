class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> need(128, 0);
        for (char c : t) {
            need[c]++;
        }

        int tot = t.length();
        int left = 0;
        int minlen = INT_MAX;
        int st = 0;

        for (int right = 0; right < s.length(); right++) {
            if (need[s[right]] > 0) {
                tot--;
            }

            need[s[right]]--;
            while (tot == 0) {
                int currentLen = right - left + 1;
                if (currentLen < minlen) {
                    minlen = currentLen;
                    st = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0) {
                    tot++;
                }
                left++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(st, minlen);
    }
};
