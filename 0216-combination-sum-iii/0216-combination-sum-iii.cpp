class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(1, k, n, curr);
        return ans;
    }
    void backtrack(int start, int k, int target, vector<int>& curr){
        if (target == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if (target < 0 || curr.size() > k) return;
        for (int num = start; num <= 9; num++){
            curr.push_back(num);
            backtrack(num + 1, k, target - num, curr);
            curr.pop_back();
        }
    }
};