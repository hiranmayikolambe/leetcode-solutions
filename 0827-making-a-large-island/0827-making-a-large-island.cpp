class Solution {
public:
    int n;
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
            return 0;
        grid[r][c] = id;
        return 1
            + dfs(grid, r + 1, c, id)
            + dfs(grid, r - 1, c, id)
            + dfs(grid, r, c + 1, id)
            + dfs(grid, r, c - 1, id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandArea;
        int id = 2;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, id);
                    islandArea[id] = area;
                    answer = max(answer, area);
                    id++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                int newArea = 1;
                unordered_set<int> seen;
                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] > 1) {
                        int neighborId = grid[nr][nc];
                        if (seen.insert(neighborId).second) {
                            newArea += islandArea[neighborId];
                        }
                    }
                }
                answer = max(answer, newArea);
            }
        }
        return answer;
    }
};