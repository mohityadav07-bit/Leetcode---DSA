class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        long double base = x;
        long double ans = 1.0;

        if (p < 0) {
            base = 1.0L / base;
            p = -p;
        }

        while (p > 0) {
            if (p & 1) {
                ans *= base;
            }

            base *= base;
            p >>= 1;
        }

        return (double)ans;
    }
};
