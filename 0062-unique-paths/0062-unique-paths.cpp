class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> nextRow(n, 0);
        for (int row = m - 1; row >= 0; row--) {
            vector<int> currentRow(n, 0);
            for (int column = n - 1; column >= 0; column--) {
                if (row == m - 1 && column == n - 1) {
                    currentRow[column] = 1;
                    continue;
                }
                int downPaths = nextRow[column];
                int rightPaths = column + 1 < n ? currentRow[column + 1] : 0;
                int current = downPaths + rightPaths;
                currentRow[column] = current;
            }
            nextRow = currentRow;
        }
        return nextRow[0];
    }
};

