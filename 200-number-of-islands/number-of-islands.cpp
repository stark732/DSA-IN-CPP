class Solution {
public:
    int n, m;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    bool valid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }


    void bfs(int i, int j, vector<vector<char>>& grid){
        if(!valid(i,j) || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        
        for(int k = 0; k<4; k++){
            int ni = i + row[k];
            int nj = j + col[k];

            if(valid(ni, nj)){
                bfs(ni, nj, grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        n  = grid.size();
        m = grid[0].size();
        int count = 0; 
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == '1') 
                    {
                        count++;
                
                bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};