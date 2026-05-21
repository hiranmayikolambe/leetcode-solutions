class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxval;
        int ans = maxval;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalh = calculatetotalhours(piles, mid);
            if (totalh <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    long long calculatetotalhours(vector<int>& piles, int speed) {
        long long totalhours = 0;
        for (int pile : piles) {
            totalhours += ceil((double)pile / speed);
        }
        return totalhours;
    }
};