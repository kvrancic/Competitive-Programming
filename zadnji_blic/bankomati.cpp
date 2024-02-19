#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pii pair<int, int>
map<pii, bool> mp;

ll numberOfPaths(int m, int n)
{
    ll path = 1;
    for (ll i = n; i < (m + n - 1); i++) {
        path = (path * i);
        path = (path/(i - n + 1));
    }
    return path%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if(k == 0){
        cout << numberOfPaths(n, n);
    }
    else{
            for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            mp[make_pair(x, y)] = true;
            }
            vector<vector<ll>> dp(n+1, vector<ll>(n+1));
            dp[1][1] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == 1 && j == 1) continue;
                    if (mp[make_pair(i, j)]) continue;
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
                }
            }
            cout << dp[n][n] << endl;
    }
    
    return 0;
}
