class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        for (int i = 0; i < nums.size(); i++){
            int Prod = 1;
            for (int j = i; j < nums.size(); j++){
                Prod *= nums[j];
                maxProd = max(maxProd, Prod);
            }
        }
        return maxProd;
    }
};