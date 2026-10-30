class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = s.size(), m = t.size();
        int i = 0;
        for (int j = 0; j < m && i < n; j++){
            if (s[i] == t[j]) i++;
        }
        return i == n;
    }
};