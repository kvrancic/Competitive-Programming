#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    long long int suma = 0; 
    int N; 
    int x; 
    cin >> N; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
        {
            cin >> x;
            suma += x;  
        }
    }

    cout << suma; 

    return 0;
    
}