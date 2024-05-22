class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int r=0;int c=m-1;
        while(c>=0 && r<n)
        {
            if(matrix[r][c]==target){return true;}
            else if(matrix[r][c]>target){c--;}
            else{r++;}
        }
        return false;

        
    }
};