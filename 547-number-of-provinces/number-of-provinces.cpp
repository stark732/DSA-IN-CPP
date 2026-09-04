class Solution {
public:
    void DFS(int node,vector<vector<int>>& adj, vector<bool>&visited){
        visited[node] = true;

        for(int i = 0; i<adj[node].size(); i++){
            if(adj[node][i] ==1 && !visited[i]){
                DFS(i,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int count = 0;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                DFS(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};