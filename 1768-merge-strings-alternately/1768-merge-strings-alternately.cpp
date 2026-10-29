class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        const int n = word1.size(), m = word2.size();
        ans.reserve(n+m);
        int common = min(n, m);
        int i = 0;
        for (; i < common; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        ans.append(word1, i, string :: npos);
        ans.append(word2, i, string :: npos);
        return ans;
    }
};