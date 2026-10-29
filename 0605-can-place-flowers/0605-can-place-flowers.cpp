class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int sz = flowerbed.size();
        bool prevFilled = false;

        for (int i = 0; i < sz && n > 0; ++i) {
            const bool nextFilled = (i + 1 < sz) && flowerbed[i + 1] == 1;
            if (flowerbed[i] == 0 && !prevFilled && !nextFilled) {
                --n;
                prevFilled = true;
            } else {
                prevFilled = (flowerbed[i] == 1);
            }
        }

        return n == 0;
    }
};