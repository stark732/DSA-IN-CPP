class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto road : roads) {

            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // shortest distance
        vector<long long> dist(n, LLONG_MAX);

        // number of ways
        vector<int> ways(n, 0);

        // {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = 1e9 + 7;

        while(!pq.empty()) {

            long long wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(wt > dist[node])
                continue;

            for(auto it : adj[node]) {

                int next = it.first;
                int dis = it.second;

                // shorter path
                if(wt + dis < dist[next]) {

                    dist[next] = wt + dis;

                    ways[next] = ways[node];

                    pq.push({dist[next], next});
                }

                // same shortest path
                else if(wt + dis == dist[next]) {

                    ways[next] =
                        (ways[next] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};