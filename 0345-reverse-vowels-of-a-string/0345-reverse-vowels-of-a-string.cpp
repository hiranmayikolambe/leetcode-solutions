class Solution {
public:
    string reverseVowels(string s) {
        bool isVowel[128] = {};
        for (char c : string("aeiouAEIOU"))
            isVowel[c] = true;

        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel[(unsigned char)s[l]]) l++;
            while (l < r && !isVowel[(unsigned char)s[r]]) r--;
            if (l < r) swap(s[l++], s[r--]);
        }

        return s;
    }
};