class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        auto getInterval = [&](int l) -> pair<int, int> {
            int r = last[s[l] - 'a'];
            for (int i = l; i <= r; i++) {
                int c = s[i] - 'a';
                if (first[c] < l) return {-1, -1};
                r = max(r, last[c]);
            }
            return {l, r};
        };
        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;
            auto interval = getInterval(first[c]);
            if (interval.first != -1) intervals.push_back(interval);
        }
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        vector<string> result;
        int prevEnd = -1;
        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                result.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        return result;
    }
};