class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums2) {
            nums1.push_back(num);
        }
        
        sort(nums1.begin(), nums1.end());
        int tot = nums1.size();
        
        if (tot % 2 == 1) {
            return nums1[tot / 2];
        } else {
            return (nums1[(tot / 2) - 1] + nums1[tot / 2]) / 2.0;
        }

    }
};
