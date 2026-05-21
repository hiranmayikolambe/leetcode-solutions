class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarysearch(nums, target, true), binarysearch(nums,target,false)};
    }
    int binarysearch(vector<int> &nums, int target, int binary){
        int low = 0, high = nums.size() - 1;
        int ans = -1;        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                ans = mid;
                if (binary) high = mid - 1;
                else low = mid + 1;
            }else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};