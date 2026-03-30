#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    
    int n{};        // number of items
    int d{};        // maximum number of dividers available
    cin >> n >> d;

    // Store item prices in the original order from the conveyor belt.
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // prefixSum[i] = total cost of the first i items
    // This lets us quickly find the sum of any group from k to i - 1.
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + prices[i - 1];
    }

    // Large value used to represent an unreachable or not-yet-computed state.
    int INF = 1000000000;

    // dp[g][i] = minimum cost to buy the first i items
    // using exactly g dividers.
    vector<vector<int>> dp(d + 1, vector<int>(n + 1, INF));

    // Base case: buying 0 items costs 0.
    dp[0][0] = 0;

    // Base case for 0 dividers:
    // all first i items must be bought in one single group.
    for (int i = 1; i <= n; i++) {
        int sum = prefixSum[i];
        dp[0][i] = ((sum + 5) / 10) * 10;
    }

    // Try using 1 divider up to d dividers.
    for (int g = 1; g <= d; g++) {
        for (int i = 1; i <= n; i++) {
            // Try placing the last divider after item k - 1,
            // so the final group is items k through i - 1.
            for (int k = 0; k < i; k++) {
                int previousCost = dp[g - 1][k];
                int groupSum = prefixSum[i] - prefixSum[k];        // sum from k to i-1
                int roundedGroupCost = ((groupSum + 5) / 10) * 10;
                int totalCost = previousCost + roundedGroupCost;

                if (totalCost < dp[g][i]) {
                    dp[g][i] = totalCost;
                }
            }
        }
    }

    // We are allowed to use up to d dividers,
    // so take the best answer over all valid divider counts.
    int answer = INF;
    for (int g = 0; g <= d; g++) {
        if (dp[g][n] < answer) {
            answer = dp[g][n];
        }
    }

    cout << answer << endl;
}
