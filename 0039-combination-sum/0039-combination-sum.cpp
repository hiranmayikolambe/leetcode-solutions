class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0, target, candidates, curr);
        return ans;
    }
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& curr){
        if (target == 0){
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            backtrack(i, target - candidates[i], candidates, curr);
            curr.pop_back();
        }
    }
};