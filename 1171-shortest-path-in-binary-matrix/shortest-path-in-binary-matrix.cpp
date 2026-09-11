class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        if(n == 0 || m == 0 || grid[0][0] ==1)
            return -1;

        queue<pair<int,int>>q;

        q.push({0,0});
        grid[0][0] = 1;
        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                auto temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                if(i == n-1 && j == m-1)
                    return count+1;

                for(int k = 0; k<8; k++){
                    int ni = i + row[k];
                    int nj = j + col[k];
                    
                    if(ni>=0 && ni<n &&
                        nj>=0 && nj<m &&
                        grid[ni][nj] == 0 )
                    {
                        q.push({ni,nj});
                        grid[ni][nj] = 1;
                    }
                }
            }
                        count++;
        }
        return -1;
    }
};