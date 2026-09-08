class Solution {
public:
    int r,c;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j){
        return i>=0&& i< r && j >=0 && j< c;
    }

    void bfs(int i, int j, vector<vector<char>>& board){
        if(!valid(i,j) || board[i][j] !='O')
            return;
        
        board[i][j] = 't';

        for(int k =0; k<4; k++){
            int ni = i+row[k];
            int nj = j + col[k];

            if(valid(ni,nj))
                bfs(ni,nj,board);
        }
    }

    void solve(vector<vector<char>>& board) {
         r = board.size();
         c = board[0]. size();

        for(int i = 0; i< r; i++){
            if(board[i][0] == 'O')
                bfs(i,0,board);
            
            if(board[i][c-1] == 'O')
                bfs(i, c-1,board);
        }

        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O')
                bfs(0,j,board);
            
            if(board[r-1][j] == 'O')
                bfs(r-1,j,board);
        }

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 't'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};