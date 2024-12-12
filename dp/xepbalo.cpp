#include <iostream>
#include <vector>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: if there's no item or the capacity is 0
            else if (wt[i - 1] <= w) // Check if current item can be included
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);  // Take the maximum of including or excluding the item
            else
                dp[i][w] = dp[i - 1][w];  // If the item can't be included
        }
    }

    // Print the DP table (optional for debugging)
    cout << "DP Table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Return the maximum value that can be obtained with capacity W
    return dp[n][W];
}

// Driver Code
int main() {
    vector<int> profit = {3,2,3,1,3,2,3,1,3,1};
    vector<int> weight = {7,9,5,8,9,5,6,7,6,5};
    int W = 45;
    cout << "Maximum value in Knapsack = " << knapSack(W, weight, profit) << endl;
    return 0;
}
