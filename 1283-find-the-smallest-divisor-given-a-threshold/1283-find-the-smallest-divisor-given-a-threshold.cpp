class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high){
            int mid = (low + high) / 2;
            if (smallD(nums, mid) <= threshold){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int smallD(vector<int> nums, int d){
        int sum = 0;
        for (int num : nums){
            sum += ceil((double)num / d);
        }
        return sum;
    }
};