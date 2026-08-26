class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int st =0;
        int end =n-1;
        int leftmax= 0;
        int rightmax=0;

        while (st < end) {
            if (height[st] <= height[end]) {
                if (height[st] >= leftmax) {
                    leftmax =height[st];
                } else {
                    total +=leftmax - height[st];
                }
                st++;
            } else {
                if (height[end] >= rightmax) {
                    rightmax =height[end];
                } else {
                    total += rightmax -height[end];
                }
                end--;
            }
        }

        return total;
    }
};
