class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int st=0;
        int end=n-1;
        int maxarea = 0;
        while(st<end){
            int area = min(heights[st], heights[end]) * (end-st);
            if(heights[st] >= heights[end]){
                end--;
            }
            else st++;
            maxarea = max(maxarea, area);
        }


        return maxarea;
    }
};
