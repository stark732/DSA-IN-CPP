class Solution {
public:

    pair<int,int>getposition(int num, int n){
        int row = n-1-(num-1)/n;
        int col = (num-1)%n;
        if((n-1-row) %2 == 1)
            col = n-1-col;

        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int>visited(n*n+1, 0);
        queue<int>q;

        q.push(1);
        visited[1] = 1;
        int moves = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                for(int dice = 1; dice <= 6; dice ++){
                    int next = dice + curr;

                    if(next > n*n)
                        break;
                    
                    auto[row,col] = getposition(next,n);

                    if(board[row][col]!= -1){
                        next = board[row][col];
                    }
                    if(next == n*n)
                        return moves +1 ;

                    if(!visited[next]){
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};