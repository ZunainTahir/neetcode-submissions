class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            int j = target - nums[i];
            
            if(mp.find(j) != mp.end()){
                ans.push_back(mp[j]);
                ans.push_back(i);
            }

            mp[nums[i]] = i;
        }
        return ans;
    }
};
