#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N], b[N], f[N][N];

int main() {
cin >> n;
for (int i = 1; i <= n; i++) cin >> a[i];
for (int i = 1; i <= n; i++) cin >> b[i];
sort(a + 1, a + n + 1);
sort(b + 1, b + n + 1);
memset(f, -0x3f, sizeof f);
f[0][0] = 0;
for (int i = 1; i <= n; i++) {
for (int j = 0; j <= i; j++) {
if (j) f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i] + b[j]);
f[i][j] = max(f[i][j], f[i - 1][j]);
}
}
int ans = 0;
for (int i = 0; i <= n; i++) ans = max(ans, f[n][i]);
cout << ans << endl;
return 0;
}