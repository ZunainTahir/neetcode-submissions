class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int count = 0;
        int left = 0;
        vector<int> vec(26, 0);
        for(int right=0;right<n;right++){
            vec[s[right] - 'A']++;
            count = max(count, vec[s[right] - 'A']);
            while ((right - left + 1) - count > k) {
                vec[s[left] - 'A']--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
