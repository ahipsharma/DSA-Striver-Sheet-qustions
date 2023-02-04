class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
        while(left < right && top < bottom){
            for(int i=left; i<right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for(int i=top; i<bottom; i++)
                ans.push_back(matrix[i][right-1]);
            right--;

            if(!(left<right && top<bottom))
                break;
            
            for(int i=right-1; i>left-1; i--)
                ans.push_back(matrix[bottom-1][i]);
            bottom--;

            for(int i = bottom-1; i>top-1; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};