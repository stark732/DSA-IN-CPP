class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>graph(n);

        for(int i = 0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt= flights[i][2];

            graph[u].push_back({v, wt});
        }

        queue<pair<int, pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);

        dist[src] = 0;
        q.push({src,{0,-1}});

        while(!q.empty()){
            auto val = q.front();

            int node = val.first;
            int cost = val.second.first;
            int steps = val.second.second;

            q.pop();

             if(steps+1 > k) continue;

            for(auto neighbour : graph[node]){
                int v = neighbour.first;
                int wt = neighbour.second;

                if(dist[v] >  cost + wt ){
                    dist[v] = cost + wt;
                    q.push({v,{dist[v],steps+1}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
    }
};