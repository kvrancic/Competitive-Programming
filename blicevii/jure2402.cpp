#include <bits/stdc++.h>

using namespace std;

struct Friend {
  int x, y, id;
};

bool compare(Friend a, Friend b) { return a.x > b.x; }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n;
    cin >> n;
    Friend ekipa[500];
    for (int i = 0; i < n; i++) {
        cin >> ekipa[i].x;
        ekipa[i].id = i;
    }

    for (int i = 0; i < n; i++) cin >> ekipa[i].y;

    sort(ekipa, ekipa + n, compare);

    int y, j;
    cin >> y >> j;

    int dp[500 + 1][500 + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= y; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= y; j++) {
        if (j >= ekipa[i - 1].y) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ekipa[i - 1].y] + ekipa[i - 1].x);
        } else {
            dp[i][j] = dp[i - 1][j];
        }
        }
    }
    cout << dp[n][y] + j;
    return 0;
}