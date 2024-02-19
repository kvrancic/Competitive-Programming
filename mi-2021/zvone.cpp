#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n, k, x; 
    int brojac = 0; 
    cin >> n >> k; 
    for(int i = 0; i < k; i++){
        cin >> x;
        if(x != n && !((n % 2 == 0) && (x == n/2))) brojac++;  
    }

    cout << (1 << brojac);     

    return 0;
    
}