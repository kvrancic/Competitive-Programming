#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, q, cnt[N][26];
string s[N];

void add(int x, string str) {
    for (int i = 0; i < str.size(); i++) {
        int c = str[i] - 'a';
        cnt[x][c]++;
        x = cnt[x][c];
    }
}

int dfs(int x, int k, int d) {
    if (d == s[k].size()) return k;
    int c = s[k][d] - 'a';
    for (int i = 0; i < c; i++) {
        if (cnt[x][i]) {
            int v = dfs(cnt[x][i], k, d + 1);
            k -= cnt[cnt[x][i]][v];
        }
    }
    return dfs(cnt[x][c], k, d + 1);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1);
    add(0, "");
    while (q--) {
        int k;
        cin >> k;
        cout << s[dfs(0, k, 0)] << endl;
    }
    return 0;
}
