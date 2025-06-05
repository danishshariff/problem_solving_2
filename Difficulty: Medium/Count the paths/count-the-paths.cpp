class Solution {
public:
    int dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& dp) {
        if (node == dest) return 1;
        if (dp[node] != -1) return dp[node];
        
        int totalPaths = 0;
        for (int neighbor : adj[node]) {
            totalPaths += dfs(neighbor, dest, adj, dp);
        }
        
        return dp[node] = totalPaths;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> dp(V, -1);  // -1 indicates not computed yet
        return dfs(src, dest, adj, dp);
    }
};
