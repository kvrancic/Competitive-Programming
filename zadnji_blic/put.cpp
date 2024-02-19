#include <iostream>
#include <vector>

using namespace std;

int numberOfPaths(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize first row and first column
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }

    // Fill up the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // The result is in the bottom-right corner
    return dp[n-1][n-1];
}

int main() {
    int n = 15;
    cout << numberOfPaths(n) << endl;
    return 0;
}
