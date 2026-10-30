class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int best = 0;
        while (l < r){
            const int h = min(height[l], height[r]);
            best = max(best, h * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return best;
    }
};