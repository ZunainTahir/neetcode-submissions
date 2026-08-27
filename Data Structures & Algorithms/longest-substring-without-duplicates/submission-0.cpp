class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int left = 0;
        unordered_set<char> sset;
        for(int rig = 0; rig<n; rig++){
            while(sset.find(s[rig]) != sset.end()){
                sset.erase(s[left]);
                left++;
            }

            sset.insert(s[rig]);
            maxlen = max(maxlen, rig-left+1);
        }
        return maxlen;
    }
};
