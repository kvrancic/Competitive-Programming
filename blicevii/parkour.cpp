#include <bits/stdc++.h>
using namespace std;
int n, m, matrica_ogranicenja[2005][2005], ulazni_stupci[2005];
vector<int> sortirani_cvorovi;
queue<int> cvorovi_bez_ulaznih_grana;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        matrica_ogranicenja[b][a] = 1;
        ulazni_stupci[a]++;
    }
    for (int i = 0; i < n; i++) {
        if (ulazni_stupci[i] == 0) {
            cvorovi_bez_ulaznih_grana.push(i);
        }
    }
    while (!cvorovi_bez_ulaznih_grana.empty()) {
        int trenutni_cvor = cvorovi_bez_ulaznih_grana.front();
        cvorovi_bez_ulaznih_grana.pop();
        sortirani_cvorovi.push_back(trenutni_cvor);
        for (int i = 0; i < n; i++) {
            if (matrica_ogranicenja[i][trenutni_cvor] == 1) {
                ulazni_stupci[i]--;
                if (ulazni_stupci[i] == 0) {
                    cvorovi_bez_ulaznih_grana.push(i);
                }
            }
        }
    }
    if (sortirani_cvorovi.size() < n) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << sortirani_cvorovi[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

