#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    map <int, int> podaci; 
    int n, q, c, k, brojac = 0;
    vector<int> ciljevi; 
    set<int, greater<int>> cijene; 
    cin >> n >> q; 
    for(int i = 0; i < n; i++){
        cin >> c >> k;
        podaci[c] += k; 
        cijene.insert(c);
    }

    for(int i = 0; i < q; i++)
    {
        int x; 
        cin >> x; 
        ciljevi.push_back(x);
    }


    for(int i : ciljevi){
        int suma = 0;
        for(int j : cijene){
            suma += podaci[j];
            if(suma >= i) {
                cout << j << endl;
                break;
            }
        }

        if(suma < i) cout << -1 << endl; 
    }
    
}