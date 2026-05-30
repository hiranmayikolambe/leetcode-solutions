class Solution {
public:
    static const long long MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long evenpos = (n + 1) / 2;
        long long oddpos = n / 2;
        long long evenway = power(5, evenpos);
        long long oddway = power(4, oddpos);
        return (evenway * oddway) % MOD;
    }
    long long power(long long base, long long exp){
        long long result = 1;
        while (exp > 0){
            if (exp & 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
};