#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
bool prime[N];
int sum[N];
vector<int> primes;

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
}

int factorSum(int n) {
    int ans = 0;
    for (int i = 0; primes[i] <= n / primes[i]; i++) {
        while (n % primes[i] == 0) {
            ans += primes[i];
            n /= primes[i];
        }
    }
    if (n > 1) {
        ans += n;
    }
    return ans;
}

int main() {
    sieve();
    for (int i = 1; i < N; i++) {
        if(!prime[i]) {
            int sumOfPrimeFactors = factorSum(i);
            if (prime[sumOfPrimeFactors]) {
                sum[i] = sum[i - 1] + 1;
            } else {
                sum[i] = sum[i - 1];
            }
        } else {
            sum[i] = sum[i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
    return 0;
}
