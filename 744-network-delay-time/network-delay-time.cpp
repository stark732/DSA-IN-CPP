class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);

        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v,wt});
        }

        vector<int>dist(n+1, INT_MAX);

        priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>>pq;

        dist[k] =0;
        pq.push({0,k});

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto val : graph[node]){
                int next = val.first;
                int wt =val.second;

                if(time + wt < dist[next]){
                    dist[next] = time + wt;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
           if( dist[i] == INT_MAX)
            return -1;
            
            ans = max(ans, dist[i]);
        }

    return ans;
    }
};