class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));

        priority_queue<pair<int, pair<int,int>>,
                vector<pair<int, pair<int,int>>>,
                greater<pair<int, pair<int,int>>>
                > pq;

        dist[0][0] = 0;

        pq.push({0,{0,0}});

        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};

        while(!pq.empty()){
            auto [effort, ceil] = pq.top();
            pq.pop();

            int i = ceil.first;
            int j = ceil.second;

            if(i == n-1 && j == m-1){
                return effort;
            }

            if(effort > dist[i][j])
                continue;

            for(int k = 0; k<4; k++){
                int ni = i + row[k];
                int nj = j + col[k];

                if(ni>=0 && ni<n && nj >=0 && nj<m){
                    int diff = abs( heights[i][j] - heights[ni][nj]);

                    int neweffort = max(effort, diff);

                    if(neweffort< dist[ni][nj]){
                        dist[ni][nj] = neweffort;
                        pq.push({neweffort,{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};