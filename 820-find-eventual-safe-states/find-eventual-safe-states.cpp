class Solution {
public:
    vector<int> state;

    bool dfs(int node, vector<vector<int>>& graph) {

        // Already visiting -> cycle
        if (state[node] == 1)
            return false;

        // Already checked
        if (state[node] == 2)
            return true;

        // Mark as visiting
        state[node] = 1;

        for (int next : graph[node]) {

            if (!dfs(next, graph))
                return false;
        }

        // No cycle found
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        state.resize(n, 0);

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (dfs(i, graph))
                ans.push_back(i);
        }

        return ans;
    }
};