class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low < high){
            int mid = low + (high - low) / 2;
            int needed = daysneeded(weights, mid);
            if (needed <= days){
                high = mid;
            }else {
                low = mid + 1;
            }
        }
        return low;
    }
    int daysneeded(vector<int>& weights, int capacity){
        int noofdays = 1;
        int currentload = 0;
        for (int w : weights){
            if (currentload + w > capacity){
                noofdays++;
                currentload = w;
            }else {
                currentload += w;
            }
        }
        return noofdays;
    }
};