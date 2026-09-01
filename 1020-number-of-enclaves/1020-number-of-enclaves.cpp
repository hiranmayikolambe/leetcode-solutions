class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++){
            if (grid[i][0] == 1 ){
                grid[i][0] = 0 ;
                q.push({i, 0});
            }
            if (grid[i][n - 1] == 1 ){
                grid[i][n - 1] = 0;
                q.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; j++){
            if (grid[0][j] == 1 ){
                grid[0][j] = 0 ;
                q.push({0, j});
            }
            if (grid[m - 1][j] == 1 ){
                grid[m - 1][j] = 0 ;
                q.push({m - 1, j});
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()){
            auto[r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 ){
                    grid[nr][nc] = 0 ;
                    q.push({nr, nc});
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};