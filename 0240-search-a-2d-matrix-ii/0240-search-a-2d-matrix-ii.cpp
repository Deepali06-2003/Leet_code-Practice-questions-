class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i =0;i<n;i++){
            int l = 0 , h = m-1;

            while(l<=h){
                int m = (l+h)/2;

                if(matrix[i][m] == target)return true;
                else if(matrix[i][m] > target)h=m-1;
                else l = m+1;
            }
        }return false;

 
    }
};