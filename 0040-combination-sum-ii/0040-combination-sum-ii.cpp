class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, curr);
            curr.pop_back();
        }
    }
};