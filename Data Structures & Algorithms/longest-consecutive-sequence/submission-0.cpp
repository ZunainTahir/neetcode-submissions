class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set snum(nums.begin(), nums.end());
        int maxlen = 0;
        for (int num : snum) {
            if (snum.find(num - 1) == snum.end()) {
                int curr = num;
                int len = 1;
                while (snum.find(curr + 1) != snum.end()) {
                    curr++;
                    len++;
                }
                maxlen = max(maxlen, len);
            }
        } 
        return maxlen;
    }
};
