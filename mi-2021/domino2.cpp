#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
     int n, q; 
     vector<pair<int, int>> arr; 
     for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        pair<int, int> par;
        par.first = x; 
        par.second = h; 
        arr.push_back(par);
     }

    // zelim stvoriti polje koje ce mi govoriti koliko ce domina pasti ako srusim dominu na tom indeksu 
    int cnt = 1; //cnt nam za svaku dominu govori koja je to domina za redom koja je pala
    vector<int> val; //sprema cntove, ali kad ih okrenem forom u foru će nam reći koliko će domina pasti ako tu prevrnemo -> ono što tražimo 
    val.push_back(cnt); //prvi element
    int startIndex = 0; 
    for(int i = 1; i < n; i++){
        if(arr[i - 1].second > arr[i].first - arr[i-1].first) val.push_back(++cnt);
        else{
            reverse(val.begin() + startIndex, val.begin() + startIndex + cnt - 1); 
            cnt = 1; 
        }
    }
    // napravili smo to polje 
    // od njega bi bilo dobro napraviti diff array da bi mogli kontrolirati preklapanja 

    

    return 0;
    
}