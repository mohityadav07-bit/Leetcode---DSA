class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapest = INT_MAX;
        vector<int> profit(n);

        for (int i = 0; i < n; i++) {
            cheapest = min(cheapest, items[i][1]);

            profit[i] = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    profit[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + profit[i]);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / cheapest);
        }

        return ans;
    }
};