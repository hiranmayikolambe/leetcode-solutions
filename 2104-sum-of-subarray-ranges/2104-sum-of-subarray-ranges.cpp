class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<long long> leftMin(n), rightMin(n);
        vector<long long> leftMax(n), rightMax(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long maxSum = 0;
        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum += 1LL * nums[i] * leftMax[i] * rightMax[i];
            minSum += 1LL * nums[i] * leftMin[i] * rightMin[i];
        }
        return maxSum - minSum;
    }
};