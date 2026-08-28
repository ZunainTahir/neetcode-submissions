class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto [ind, ht] = st.top();
                st.pop();
                area = max(area, ht * (i - ind));
                start = ind; // Current bar can extend back to where popped bar started
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            auto [ind, ht] = st.top();
            st.pop();
            area = max(area, ht * (n - ind));
        }

        return area;
    }
};
