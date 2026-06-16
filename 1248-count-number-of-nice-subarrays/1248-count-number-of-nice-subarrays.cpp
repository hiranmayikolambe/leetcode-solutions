class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int count = 0, oddcount = 0;
        for (int num : nums){
            if (num % 2 != 0) oddcount++;
            if (freq.count(oddcount - k)) count += freq[oddcount - k];
            freq[oddcount]++;
        }
        return count;
    }
};