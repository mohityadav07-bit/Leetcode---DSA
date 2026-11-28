class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minP = INT_MAX, mx = 0;

        for (auto &it : items) {
            minP = min(minP, it[1]);
            mx = max(mx, it[0]);
        }

        vector<int> cnt(mx + 1, 0);

        for (auto &it : items)
            cnt[it[0]]++;

        for (int i = 1; i <= mx; i++) {
            for (int j = 2 * i; j <= mx; j += i) {
                cnt[i] += cnt[j];
            }
        }

        sort(items.begin(), items.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        long long ans = 0;
        long long rem = budget;

        for (auto &it : items) {
            int f = it[0], p = it[1];

            if (p > 2LL * minP)
                break;

            int bonus = cnt[f] - 1;
            if (bonus <= 0)
                continue;

            long long take = min(rem / p, (long long)bonus);

            ans += 2LL * take;
            rem -= take * p;
        }

        ans += rem / minP;

        return (int)ans;
    }
};