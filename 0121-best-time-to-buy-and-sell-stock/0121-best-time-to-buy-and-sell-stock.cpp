class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxP = 0;
        for (int price : prices){
            if (price < minprice) minprice = price;
            else maxP = max(maxP, price - minprice);            
        }
        return maxP;
    }
};