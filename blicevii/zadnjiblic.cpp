#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long bankomati[10001];
long long memo[10001][10001];

long long solve(long long x, long long y, long long n) {
    if (memo[x][y] != -1) return memo[x][y];
    if (x == 1 or y == 1) return 1;
    return memo[x][y] = (solve(x - 1, y, n) + solve(x, y - 1, n)) % mod;
}

int main() {

    long long n, k;
    cin >> n >> k;

    for (int i = 0; i < 10001; ++i) bankomati[i] = 0;

    for (int i = 0; i < 10001; ++i) {
        for (int j = 0; j < 10001; ++j) {
            if (i == 1 or j == 1) memo[i][j] = 1;
            else memo[i][j] = -1;
        }
    }

    for (int i = 0; i < k; ++i) {
        long long x, y;
        cin >> x >> y;
        memo[x][y] = 0;
    }

    cout << solve(n, n, n);

    return 0;
}
