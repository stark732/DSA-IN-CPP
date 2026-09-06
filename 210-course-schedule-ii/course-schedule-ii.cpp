class Solution {
public:

    vector<int> topo(vector<vector<int>>&adj, int num,vector<int>&indegree ){
        queue<int>q;
        vector<int>ans;
        int count = 0;

        for(int i = 0; i < num; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            count++;

            for(int neighbour : adj[u]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(count == num){
            return ans;
        }else{
            return {};
        }
    }

    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(num);
        vector<int>indegree(num,0);

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
            indegree[u]++;
        }
        return topo(adj, num, indegree);
    }
};