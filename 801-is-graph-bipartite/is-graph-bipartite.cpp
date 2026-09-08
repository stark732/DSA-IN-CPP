class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);


        for(int i = 0; i<n; i++){
            if(visited[i] != -1)
                continue;

            queue<int>q;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto neighbour : graph[node]){
                    if(visited[neighbour] == -1){
                        visited[neighbour] = 1 - visited[node];
                        q.push(neighbour);
                    }
                    else if(visited[neighbour] == visited[node]){
                        return false;
                    }

                }
            }
        }
        return true;
    }
};