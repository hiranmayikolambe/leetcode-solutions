class Solution {
public:
    long long findPascalElement(int r, int c) {
        int n = r - 1;
        int k = c - 1;

        long long result = 1;
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int r = 1; r <= numRows; r++) {
            vector<int> row;
            for (int c = 1; c <= r; c++) {
                row.push_back(findPascalElement(r, c));
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};