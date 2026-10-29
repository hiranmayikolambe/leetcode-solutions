class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int maxCandy = *max_element(candies.begin(), candies.end());
        const int threshold = maxCandy - extraCandies;
        vector<bool> ans;
        ans.reserve(candies.size());
        for (int c : candies){
            ans.push_back(c >= threshold);
        }
        return ans;
    }
};