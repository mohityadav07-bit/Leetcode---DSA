
class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;

        for (long long i = 1; i <= n; i *= 10) {
            long long num = n / (i * 10);
            long long rem = n % (i * 10);

            count += num * i;

            if (rem >= i) {
                count += min(rem - i + 1, i);
            }
        }

        return count;
    }
};

