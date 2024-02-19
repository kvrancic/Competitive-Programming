#include <bits/stdc++.h>
using namespace std;

void pp(int *a, int n) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int temp = a[i];
        a[i] = c;
        if (!temp) c++;
    }
    for (int i = 0; i < n; ++i){
        cout << a[i] << ", ";
    }
}

bool has_solution(int *a, int n, int m, int s, int t) { //t kolko radnih dana do početka praznika
    for(int i = 0; i <= n-t+1; ++i) {
        for(int j = i+t; j <= n-t; ++j) {
            int radni = a[i+t]-a[i]+a[j+t]-a[j];
            if (radni<=s && (n >= (m+s))) return true;
        }
    }
    return false;
// }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    int l = 0, h = 0, mid = 0;
    cin >> n >> m;
    int a[n] = {0};
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        a[k - 1] = 1;
    }
    cin >> s;

    pp(a, n);

    
    l = 0;
    h = n;
    mid = n / 2;

    int solution = 0;
    while (l != h) {
        if (has_solution(a, n, m, s, mid)) { //paše, znači probajemo dalje
            solution = mid;
            l = mid+1;
            mid = (l + h) / 2;
        }
        else {      // ne paše, idemo na manji broj 
            h = mid;
            mid = (l + h) / 2;
        }
    }

    cout << solution << endl;
}