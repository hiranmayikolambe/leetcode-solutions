class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(
            rows, vector<int>(cols, INT_MAX)
        );
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;
        effort[0][0] = 0;
        pq.push({0, 0, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [currEffort, r, c] = pq.top();
            pq.pop();
            if (currEffort > effort[r][c])
                continue;
            if (r == rows - 1 && c == cols - 1)
                return currEffort;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols)
                    continue;
                int diff = abs(
                    heights[r][c] - heights[nr][nc]
                );
                int newEffort = max(currEffort, diff);
                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};