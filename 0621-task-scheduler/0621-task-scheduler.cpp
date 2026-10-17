class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;
        int f = *max_element(freq.begin(), freq.end());
        int cnt = count(freq.begin(), freq.end(), f);
        return max((int)tasks.size(), (f - 1)*(n + 1)+ cnt);
    }
};