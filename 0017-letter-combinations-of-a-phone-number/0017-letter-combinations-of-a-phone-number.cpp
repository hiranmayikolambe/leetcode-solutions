class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
        string curr;
        backtrack(0, digits, curr, mapping);
        return ans;
    }
    void backtrack(int ind, string& digits, string& curr, vector<string>& mapping){
        if (ind == digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters = mapping[digits[ind] - '0'];
        for (char ch : letters){
            curr.push_back(ch);
            backtrack(ind + 1, digits, curr, mapping);
            curr.pop_back();
        }
    }
};