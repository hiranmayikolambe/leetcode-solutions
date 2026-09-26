class Solution {
public:
    vector<int> parent, rank_;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string, int> emailOwner;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailOwner.count(email)) {
                    unite(i, emailOwner[email]);
                } else {
                    emailOwner[email] = i;
                }
            }
        }
        unordered_map<int, vector<string>> mergedEmails;
        for (auto& [email, account] : emailOwner) {
            int root = find(account);
            mergedEmails[root].push_back(email);
        }
        vector<vector<string>> result;
        for (auto& [root, emails] : mergedEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(accounts[root][0]);
            for (string& email : emails)
                account.push_back(email);
            result.push_back(account);
        }
        return result;
    }
};