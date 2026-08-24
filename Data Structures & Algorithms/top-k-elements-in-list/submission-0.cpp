class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> vec;
        for(int num:nums){
            mp[num]++;
        }

        vector<pair<int,int>> freq;

        for(auto f: mp){
            freq.push_back({f.second, f.first});
        }

        sort(freq.rbegin(), freq.rend());

        for(int i=0;i<k;i++){
            vec.push_back(freq[i].second);
        }
        return vec;
    }
};
