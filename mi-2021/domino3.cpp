#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
     int n, q; 
     vector<pair<int, int>> arr; 
     cin >> n;
     for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        pair<int, int> par;
        par.first = x; 
        par.second = h; 
        arr.push_back(par);
     }

    //polje u kojem gledamo baca li ga prethodnik -> da kasnije možemo pregledavati niz jedinica od s + 1
    vector<int> val; 
    val.push_back(0);
    for(int i = 1; i < n; i++){
        if(arr[i - 1].second >= arr[i].first - arr[i-1].first) val.push_back(1);
        else val.push_back(0);
    }

    //cout << "Stanje u nizu: ";
    //for(int i : val) cout << i << ", ";
    //cout << endl;
    

    cin >> q;
    vector<int> rez; 
    int m, s, x; 
    for(int cnt = 0; cnt < q; cnt++){ //brojac upita
        cin >> m;
        int suma = 0; 
        vector<int> nval = val; 
        for(int br = 0; br < m; br++){ //brojac bacenih domina
            cin >> s; 
            s -= 1; //da se prilagodi indeksima 
            if(nval[s + 1] == 0){
                nval[s] = -1; 
                x = 1; 
            }
            else if(nval[s] == - 1){
                x = 0; 
            }
            else if(nval[s + 1] == 1){
                x = 1; 
                nval[s] = -1;
                while(nval[++s] == 1){
                    x++; 
                    nval[s] = -1;
                }
            }
            suma += x;
            cout << "Padom ovog elementa palo je jos elemenata: " << x << endl;; 
        }
        rez.push_back(suma);
        //cout << "Stanje u nizu: ";
        //for(int i : val) cout << i << ", ";
        //cout << endl;
    }

    for(int i : rez) cout << i << endl;

    return 0;
    
}