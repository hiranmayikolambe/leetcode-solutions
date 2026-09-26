class Solution {
public:
    vector<vector<int>> bridges;
    vector<int> disc, low;
    int timer = 0;
    void dfs(int u, int parent, vector<vector<int>>& adj) {
        disc[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] != -1) {
                low[u] = min(low[u], disc[v]);
            }
            else {
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {
        vector<vector<int>> adj(n);
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        disc.assign(n, -1);
        low.resize(n);
        dfs(0, -1, adj);
        return bridges;
    }
};