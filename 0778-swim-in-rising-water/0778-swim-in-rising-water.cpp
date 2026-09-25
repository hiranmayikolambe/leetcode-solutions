class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();
            if (time > dist[r][c]) continue;
            if (r == n - 1 && c == n - 1) return time;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                int newTime = max(time, grid[nr][nc]);
                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
        return -1;
    }
};