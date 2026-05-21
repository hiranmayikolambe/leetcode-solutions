class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers = 1LL * m * k;
        if (totalflowers > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (ifpossible(bloomDay, mid, m, k)){
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    bool ifpossible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0;
        int bouquets = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day){
                cnt++;
                if (cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }          
        }
        return bouquets >= m;
    }
};