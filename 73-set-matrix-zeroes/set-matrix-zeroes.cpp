class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> clone = matrix;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(matrix[r][c] == 0){

                    for(int i = 0; i < col; i++){
                        clone[r][i] = 0;
                    }

                    for(int j = 0; j < row; j++){
                        clone[j][c] = 0;
                    }
                }
            }
        }
        matrix = clone;
    }
};