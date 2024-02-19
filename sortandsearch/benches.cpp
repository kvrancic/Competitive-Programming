#include <bits/stdc++.h>

using namespace std;

int main(){
    // Rješenje vašeg zadatka
        int n, m, min, max = 0, total = 0;
        cin >> n;
        cin >> m;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x > max)
                max = x;
            v.push_back(x);
        } 
        max += m;
        while (m > 0)
        {
            *min_element(v.begin(), v.end()) += 1;
            m--;
        }
        cout << *max_element(v.begin(), v.end()) << " ";
        cout << max;
        
        return 0;
}

// n klupa, ai ljudi na i-toj klupi, m ljudi dolazi i sjesi će na neko slobodno mjesto 
// k je maksimalan broj ljudi koji sjedi na jednoj klupi
// nitko ne napušta sjedalo 
// inputi n, m , ai
// traži se minimalan i maksimalan k - minimalan kad ih jednako sjedne na svaku klupu 