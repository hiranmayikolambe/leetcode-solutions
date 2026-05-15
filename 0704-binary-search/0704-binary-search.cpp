class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size() -1, target);
    }
    int binarysearch(vector<int> &nums, int low, int high, int target){
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) return binarysearch(nums, mid + 1, high, target);
        else return binarysearch(nums, low, mid - 1, target);
    }
};