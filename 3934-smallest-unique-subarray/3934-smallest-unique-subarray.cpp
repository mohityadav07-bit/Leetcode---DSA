class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), rank(n), temp(n), lcp(n);

        iota(sa.begin(), sa.end(), 0);

        for (int i = 0; i < n; i++)
            rank[i] = nums[i];

        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + k < n) ? rank[a + k] : -1;
                int y = (b + k < n) ? rank[b + k] : -1;
                return x < y;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++)
                temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n && nums[i + h] == nums[j + h])
                h++;

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int r = 0; r < n; r++) {
            int mx = lcp[r];

            if (r + 1 < n)
                mx = max(mx, lcp[r + 1]);

            if (mx < n - sa[r])
                ans = min(ans, mx + 1);
        }

        return ans;
    }
};