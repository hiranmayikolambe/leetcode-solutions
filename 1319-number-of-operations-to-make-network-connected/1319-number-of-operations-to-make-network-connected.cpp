class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                while (!st.empty()) {
                    int u = st.top();
                    st.pop();
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            st.push(v);
                        }
                    }
                }
            }
        }
        return components - 1;
    }
};