class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);

        // ans[i] = product of all elements to the left of i
        ans[0] = 1;
        for (int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];

        // multiply by product of all elements to the right of i
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};