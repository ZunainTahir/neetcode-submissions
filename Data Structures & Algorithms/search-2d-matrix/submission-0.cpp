class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();   // 3
        int n =matrix[0].size();  // 4

        int l=0;
        int r=(m*n)-1;

        while(l<=r){
            int m = l+((r-l)/2);
            int val = matrix[m/n][m%n];

            if(val==target){
                return true;
            }
            else if(val>target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }

        return false;   
    }
};
