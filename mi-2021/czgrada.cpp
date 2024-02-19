#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int x1, x2, y1, y2; 
    int n, m; 
    cin >> n; 
    cin >> m;

    int matrica[n][n];
    memset(matrica, 0, sizeof(matrica[0][0]) * n * n);

    for(int br = 0; br < m; br++){
        cin >> x1 >> y1 >> x2 >> y2; 
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                matrica[i - 1][j - 1]++;   
    }

    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << matrica[i][j] << " ";   
        cout << endl; 
    }
    */

    int rez = 0;
    for (int i = 0; i < n; i++)   
        for (int j = 0; j < n; j++)
             if(matrica[i][j] % 2 == 0) rez++;   

    cout << rez;

    return 0;
    
}