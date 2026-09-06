class Solution {
public:

    bool topological(vector<vector<int>>& adj, int n, vector<int>& indegree) {

        queue<int> q;
        int count = 0;

        // Add ALL nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Now start BFS
        while (!q.empty()) {

            int u = q.front();
            q.pop();

            count++;

            for (int neighbour : adj[u]) {

                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto edge : prerequisites) {

            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        return topological(adj, numCourses, indegree);
    }
};