#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
map<pii, bool> mp;

ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        mp[make_pair(x, y)] = true;
    }
    ll ans = pow(2, n-1);
    for (int i = 2; i <= n; i++) {
        int j = n + 1 - i;
        if (mp[make_pair(i, j)] || mp[make_pair(j, i)]) {
            ans = (ans - (ll)pow(2, n-i) + mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
